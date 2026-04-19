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
#include "particles.hpp"
using namespace std;

double h = 0.0003; //mesh cell size
double cathodepot = -5000.0; //cathode and anode potentials in volts
double anodepot = 0.0; 
double anode_r = 15*1.33 * 1e-3; //(roughly 19.95mm)

double sim_x = 0.048+0.03175; 
double sim_y = 0.096;  //measured half
double sim_z = 0.063;  //measured half (radius)

int n_nodes_x = (int) (sim_x/h);
int n_nodes_y = (int) (sim_y/h);
int n_nodes_z = (int) (sim_z/h);

void init(){
    Geometry geom(MODE_3D, Int3D(n_nodes_x, n_nodes_y, n_nodes_z), Vec3D(-0.03175,-0.048,-0.03175), h); //define geometry. cuboid with same x,y,z dimensions as tee. 

    Solid *s1 = new STLSolid("dn63 tee.stl");
    geom.set_solid(7,s1);
    Solid *s2 = new STLSolid("cathodegridnostalk.stl");
    geom.set_solid(8,s2);
    Solid *s3 = new STLSolid("anodegrid_correct_wire.stl");
    geom.set_solid(9,s3);
    
    for (uint32_t i = 1; i <= 6; i++){ //loop to set Neumann boundary condition for 6 simulation space faces
        geom.set_boundary(i, Bound(BOUND_NEUMANN, 0.0));
    }

    geom.set_boundary(7, Bound(BOUND_DIRICHLET, 0.0));
    geom.set_boundary(8, Bound(BOUND_DIRICHLET, cathodepot));
    geom.set_boundary(9, Bound(BOUND_DIRICHLET, anodepot));

    geom.build_mesh(); //create node mesh
    geom.build_surface(); //create surfaces on the solids so that the code can recognise when particles hit the surfaces. 
    geom.save("geom.dat", true);
}

int main(int argc, char **argv){
    try{
        ibsimu.set_message_threshold(MSG_VERBOSE, 1);
        ibsimu.set_thread_count(6);
        init();
    } catch(Error e){
        e.print_error_message(ibsimu.message(0));
        exit(1);
    }
    return 0;
}