
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


double h = 789; //mesh cell size
double cathodepot = 5000; //cathode potential in volts

void sim(){
    Geometry geom(MODE_3D, Int3D(0.127,0.955,0.03175), Vec3d(0,0,0), h); //define geometry. cuboid with same x,y,z dimensions as tee. 
    STLSolid *s1 chamber('dn63 tee.stl');
    geom.set_solid(s1,7);
    STLSolid *s2 cathode('cathodegrid.stl');
    geom.set_solid(s2,8);

    geom.set_boundary(1, BOUND_NEUMANN, 0);//def bound conditions
    geom.set_boundary(2, BOUND_NEUMANN, 0);
    geom.set_boundary(3, BOUND_NEUMANN, 0);
    geom.set_boundary(4, BOUND_NEUMANN, 0);
    geom.set_boundary(5, BOUND_NEUMANN, 0);
    geom.set_boundary(6, BOUND_NEUMANN, 0);
    geom.set_boundary(7, BOUND_DIRICHLET, 0);
    geom.set_boundary(8, BOUND_DIRICHLET, cathodepot);
    EpotBiCGSTABSolver solver( geom );

    InitialPlasma initp();
    solver.set_initial_plasma();

    EpotField epot(geom);
    MeshScalarField scharge(geom);
    MeshVectorField bfield;

    EpotEfield efield(epot);

    Emittance emit;
    Convergence conv;
    conv.add_epot(epot);
    conv.add_scharge(scharge);
    conv.add_emittance(emit);




    
    



}
