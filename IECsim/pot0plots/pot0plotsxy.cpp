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

void sim(int argc, char **argv){
    string geom_fn = "geom.dat";
    ifstream is_geom(geom_fn.c_str());
    if (!is_geom.good())
        throw( Error( ERROR_LOCATION, (std::string)"couldn\'t open file \'" + geom_fn + "\'" ) );
    Geometry geom( is_geom );
    is_geom.close();

    EpotField epot(geom);
    MeshScalarField scharge(geom);
    EpotEfield efield(epot);

    GeomPlotter gplotter(geom);
    gplotter.set_size(2048, 2048);
    gplotter.set_view(VIEW_XY, -1);
    gplotter.set_ranges(-0.05, -0.05, 0.05, 0.05);
    gplotter.set_epot(&epot);

    // mesh only plot - no solver run
    gplotter.set_mesh(true);
    gplotter.plot_png("xy_mesh.png");
    gplotter.set_mesh(false);

    // eps = 1.0
    EpotBiCGSTABSolver solver1(geom);
    solver1.set_eps(1.0);
    solver1.solve(epot, scharge);
    gplotter.plot_png("xy_eps1.0.png");

    // eps = 0.1
    EpotBiCGSTABSolver solver2(geom);
    solver2.set_eps(0.1);
    solver2.solve(epot, scharge);
    gplotter.plot_png("xy_eps0.1.png");

    // eps = 0.05
    EpotBiCGSTABSolver solver3(geom);
    solver3.set_eps(0.05);
    solver3.solve(epot, scharge);
    gplotter.plot_png("xy_eps0.05.png");

    // eps = 0.01
    EpotBiCGSTABSolver solver4(geom);
    solver4.set_eps(0.01);
    solver4.solve(epot, scharge);
    gplotter.plot_png("xy_eps0.01.png");
}

int main(int argc, char **argv) {
    try {
        ibsimu.set_message_threshold(MSG_VERBOSE, 1);
        ibsimu.set_thread_count(6);
        sim(argc, argv);
    } catch(Error e) {
        e.print_error_message(ibsimu.message(0));
        exit(1);
    }
    return 0;
}