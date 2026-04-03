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
    random_device rd{};
    mt19937 gen{rd()};
    normal_distribution<double> d{0.0,1.0};
    cout << d(gen) << endl;
}



