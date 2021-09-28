#include <iostream>
#include <string>
using namespace std;

int main(){
    int ntest;
    cin >> ntest;
    for(int i=0;i<ntest;i++){
        int niter;
        string str;
        cin >> niter >> str;
        for(int i=0;i<str.length();i++){
            for(int j=0;j<niter;j++){
                cout << str[i];
            }
        }
        cout << "\n";
    }
    return 0;
}