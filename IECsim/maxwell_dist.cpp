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
const double pi = 3.14159265358979323846;
const double k = 1.3806488 * 1e-23;
const double R = 8.314;

const double m = 28.0134; // u
const double q = 1; //e
 //TODO: query directly from NIST database

//Thermal gas molecule speed calculations
const double T_0 = 20.0 + 273.0;//starting temperature
const double V = 337126.98779 * 1e-9;
 //boltzmann constant
const double a = sqrt(k*T_0/m);

int main(){
    double mean_velo = 2*a*sqrt(2/pi);
    cout << a << "\n";
    cout << mean_velo << "\n";
}