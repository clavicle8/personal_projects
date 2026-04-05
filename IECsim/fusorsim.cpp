/*
*PIC Vlasov-Poisson Iterator
*Goal: produce a convergent potential map for a tee-fusor system to see if we can get a relatively uniform field
*using a second anode grid, and get a double potential well setup
*Second goal: see if it works with a fully spherical chamber and grids. 
*/


#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <random>
#include <map>
#include <string>
#include <cmath>

#include "epot_gssolver.hpp"
#include "epot_mgsolver.hpp"
#include "epot_bicgstabsolver.hpp"
#include "particledatabase.hpp"
#include "geometry.hpp"
#include "convergence.hpp"
#include "func_solid.hpp"
#include "epot_efield.hpp"
#include "meshvectorfield.hpp"
#include "meshvectorfield.hpp"
#include "ibsimu.hpp"
#include "error.hpp"
#include "particlediagplotter.hpp"
#include "geomplotter.hpp"
#include "config.h"
#include "stl_solid.hpp"

using namespace std;

//physical parameters
double starting_temp = 20.0 + 273.0;
double V = 337126.98779 * 1e-9;
double R = 8.314; //(joules per mole per kelvin)
double k = 1.3806488 * 1e-23; //boltzmann constant
double p_mbar = 9 * 1e-3; 
double n = p_mbar/(k*starting_temp); //number density
long N_lab = round(n*V); //lab no. of particles. comes out as 750041320067570 particles: too many.
// can simplify by treating particles as "clouds" (Vlasov 1950)
long N_clouds;




double h = 0.0001; //mesh cell size
double cathodepot = 5000.0; //cathode and anode potentials in volts
double anodepot = 0.0; 
double anode_r = 15*1.33 * 1e-3; //(roughly 19.95mm)

//tee geom in metres
double tee_x = 0.127; 
double tee_y = 0.0955*2;  //measured half
double tee_z = 0.03175*2; //measured half (radius)

int n_nodes_x = (int) tee_x/h;
int n_nodes_y = (int) tee_y/h;
int n_nodes_z = (int) tee_z/h;


random_device rd{};
mt19937 gen{rd()}; //mersenne-twister-engine: random number generator. 
normal_distribution<double> d{0.0,1.0};
double gaussian(){
    return d(gen);  //pluck a random number from the gaussian
}

Vec3D sample(double r){ //samples a point on a sphere of radius r
    double x = gaussian();
    double y = gaussian();
    double z = gaussian();
    double normalisation = 1/pow(x*x + y*y + z*z ,0.5); //Muller 1959, Marsaglia 1972, as seen in Weisstein (Wolfram Mathworld)

    return Vec3D(x * normalisation * anode_r, y * normalisation * anode_r, z * normalisation * anode_r);
}


void sim(){
    Geometry geom(MODE_3D, Int3D(n_nodes_x, n_nodes_y, n_nodes_z), Vec3D(0,0,0), h); //define geometry. cuboid with same x,y,z dimensions as tee. 

    Solid *s1 = new STLSolid("dn63 tee.stl");
    geom.set_solid(7,s1);
    Solid *s2 = new STLSolid("cathodegrid.stl");
    geom.set_solid(8,s2);
    Solid *s3 = new STLSolid("anodegrid.stl");
    geom.set_solid(9,s3);
    
    for (uint32_t i = 1; i <= 6; i++){ //loop to set Neumann boundary condition for 6 simulation space faces
        geom.set_boundary(i, Bound(BOUND_NEUMANN, 0.0));
    }

    geom.set_boundary(7, Bound(BOUND_DIRICHLET, 0.0));
    geom.set_boundary(8, Bound(BOUND_DIRICHLET, cathodepot));
    geom.set_boundary(9, Bound(BOUND_DIRICHLET, anodepot));

    geom.build_mesh(); //create node mesh
    geom.build_surface(); //create surfaces on the solids so that the code can recognise when particles hit the surfaces. 
    
    
    EpotBiCGSTABSolver solver(geom); //declare biconjugate gradient stabilized method for solver

    EpotField epot(geom); //declare epot field, space charge, b field objects
    MeshScalarField scharge(geom);
    MeshVectorField bfield; //empty: no b field limit 

    EpotEfield efield(epot); //declare e field
    ParticleDataBase3D pdb(geom);  //initialise particle database
    pdb.set_surface_collision(true); 

    Emittance emit;  //declare emittance statistics class. no idea about the math, but qualitatively its a measure of beam quality

    
    Convergence conv;
    conv.add_epot(epot);
    conv.add_scharge(scharge);
    conv.add_emittance(0, emit);

    //particle declaration loop
    /*
    * We randomly sample n points on a sphere as particles in our system. 
    * A
    */

    for (long i = 1; i <= N_clouds; i++ ){
        pdb.add_particle()
    }

   




    
    



}

