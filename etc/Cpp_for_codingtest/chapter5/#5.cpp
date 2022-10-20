#include <iostream>

using namespace std;

int factorial_recursive(int i){
    if(i==1){
        return 1;
    }else{
        return i*factorial_recursive(i-1);
    }
}

int factorial_iterative(int i){
    int n=1;
    while(i>1){
        n *= i;
        i--;
    }
    return n;
}

int main(){
    int n;
    cin >> n;
    cout << "recursive : " <<factorial_recursive(n) << "\n";
    cout << "iterative : " <<factorial_iterative(n);
    return 0;
}