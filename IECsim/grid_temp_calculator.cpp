/*
* Calvin Dai April 2nd 2026
* Calculator to determine whether a 3 (circular) wire IEC spherical grid (one in each plane, xyz) will survive (thermally) a certain current
* Assumes vacuum environment ==> only heat dissipation is through radiation (Stefan-Boltzmann law)
* Models grid as 12 identical wire segments (resistors). Resistance measurement is at nodes on opposite sides of the grid. The 4 middle resistors between the measurement nodes
can be ignnored as the pd drop between them is the same, so no current flows. 
* Ignores intersecting areas between the wires at the nodes for simplicity
*/

#include <iostream> //some standard cpp libraries
#include <string>
#include <math.h>
#include <stdio.h> //cus std::cout sucks. allows use of printf() from C which is way easier to use

using namespace std;

//constants
double pi = acos(-1.0);
double sigma = 5.670374419e-8; //stefan-boltzmann constant
//current to be tested

double I = 1;

//*************** MATERIAL PROPERTIES ***************//
/*
* Assumes standard 304 SS alloy, polished surface.
* Very pessimistic estimate for epsilon (polished)
* Under vacuum.
*/

string material = "304 SS";


double rho_d = 7.93; //g cm^-3
double rho_r = 7.2e-5; //ohm cm
double epsilon = 0.1;

double melting_point = 1400 + 273; //K

//*************** GRID GEOMETRY ***************//

double r_ring = 0.5; //cm
double r_wire = 0.015;
double csa =  pi * pow(r_wire,2); //wire cross-sectional-area
double l = (pi*r_ring)/2;   //length of one (of the 12) wire segment(s). Length of 1 segment is 1/4 of the circumference of the wire. simplifying, 2pi*r_ring/4 = pi*r_ring/2
double A_m2 = 24*pi*r_wire*l/1e4;
//*************** RESISTANCE ***************//

double R_segment = (rho_r * l)/csa; //resistance of one wire segment

/*
The symmetry of the system means that we can simplify the spherical model of the 12 resistors down to just 8
(same p.d. drop across middle 4 resistors, so no current through them)

An equivalent resistor map is as follows:

                       |---====----====----|
                       |---====----====----|
                       |---====----====----|
                       |---====----====----|

I.e. 4 parallel branches of 2 resistors.

Effective resistance is therefore 1/4 * 2R = R/2
*/


double R_eff = R_segment/2;
double P_in = pow(I,2) * R_eff;

double T_eq = pow(P_in/(sigma*epsilon*A_m2),0.25);

bool willmelt(){
    return T_eq >= melting_point;
}
int main() {
    printf("R_segment = %f ohm\n", R_segment);
    printf("R_eff = %f ohm\n", R_eff);
    printf("P_in = %f W\n", P_in);
    printf("A = %e m^2\n", A_m2);
    printf("T_eq = %f K\n", T_eq);
    printf("Melting point = %f K\n", melting_point);
    printf("Will melt: %s\n", willmelt() ? "yes" : "no");
}



