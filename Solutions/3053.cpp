#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    double pi = M_PI;
    cin >> n;
    double uclidarea = n*n*pi;
    double taxiarea = 2*n*n;
    cout << fixed;
    cout.precision(6);
    cout << uclidarea << "\n" << taxiarea;
    return 0;
}