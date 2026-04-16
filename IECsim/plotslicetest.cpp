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
    gplotter.set_view(VIEW_YZ, 105);
    gplotter.set_ranges(-0.05, -0.05, 0.05, 0.05);
    gplotter.set_epot(&epot);

    EpotBiCGSTABSolver solver1(geom);
    solver1.set_eps(0.05);
    solver1.solve(epot, scharge);
    gplotter.plot_png("yz_105_default.png");
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