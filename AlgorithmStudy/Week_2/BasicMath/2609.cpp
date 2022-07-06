#include <iostream>
using namespace std;

int n,m;

int gcd(int a, int b){
    int mod;
    while(b){
    mod = a%b;
    a =b ;
    b = mod;
    }
    return a;
}

int lcm(int a, int b, int c){
    return (a*b)/c;
}

int main(){
    cin >> n >> m;
    cout << gcd(n,m) << "\n" << lcm(n,m,gcd(n,m)) ;
    return 0;
}