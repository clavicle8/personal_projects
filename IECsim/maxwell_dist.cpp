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

const double m = 28.0134; // u
const double q = 1; //e
 //TODO: query directly from NIST database

//Thermal gas molecule speed calculations
const double T_0 = 20.0 + 273.0;//starting temperature
const double V = 337126.98779 * 1e-9;
const double R_const = 8.314; //(joules per mole per kelvin)
const double k = 1.3806488 * 1e-23; //boltzmann constant
const double a = sqrt(k*T_0/m);

int main(){
    cout << a << "\n";
}