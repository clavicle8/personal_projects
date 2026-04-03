
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iomanip>
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

using namespace std;


double h = 0.0001; //mesh cell size
double cathodepot = 5000; //cathode and anode potentials in volts
double anodepot = 0; 

//tee geom in metres
double tee_x = 0.127; 
double tee_y = 0.0955*2;  //measured half
double tee_z = 0.03175*2; //measured half (radius)

void sim(){
    Geometry geom(MODE_3D, Int3D(tee_x, tee_y, tee_z), Vec3d(0,0,0), h); //define geometry. cuboid with same x,y,z dimensions as tee. 
    Solid *s1 = chamber("dn63 tee.stl");// import stl for chamber
    geom.set_solid(s1,7); //pointer
    STLSolid *s2 cathode("cathodegrid.stl"); //import stl for grid
    geom.set_solid(s2,8); //pointer
    STL Solid *s3 anode("anodegrid.stl");
    geom.set_solid(s3,9)

    geom.set_boundary(1, BOUND_NEUMANN, 0);//def bound conditions
    geom.set_boundary(2, BOUND_NEUMANN, 0);
    geom.set_boundary(3, BOUND_NEUMANN, 0);
    geom.set_boundary(4, BOUND_NEUMANN, 0);
    geom.set_boundary(5, BOUND_NEUMANN, 0);
    geom.set_boundary(6, BOUND_NEUMANN, 0);
    geom.set_boundary(7, BOUND_DIRICHLET, 0);
    geom.set_boundary(8, BOUND_DIRICHLET, cathodepot);
    geom.set_boundary(9, BOUND_DIRICHLET, anodepot);

    EpotBiCGSTABSolver solver( geom ); //declare biconjugate gradient stabilized method for solver


    EpotField epot(geom);
    MeshScalarField scharge(geom);
    MeshVectorField bfield;

    EpotEfield efield(epot);

    Emittance emit;
    Convergence conv;
    conv.add_epot(epot);
    conv.add_scharge(scharge);
    conv.add_emittance(emit);

    //particle declaration loop
    /*
    * We randomly sample 
    */




    
    



}
