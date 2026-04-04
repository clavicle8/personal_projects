#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <map>
#include <string>
#include <cmath>

using namespace std;

int main(){
    //physical parameters
    double starting_temp = 20.0 + 273.0;
    double V = 337126.98779 * 1e-9;
    double R = 8.314; //(joules per mole per kelvin)
    double k = 1.3806488 * 1e-23; //boltzmann constant
    double p_mbar = 9 * 1e-3; 
    double n = p_mbar/(k*starting_temp); //number density
    double N = n * V;

    cout << N << "\n";
}