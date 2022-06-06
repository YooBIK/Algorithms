#include <iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
    int diag =1;
    int bound;
    if(n==1){
        cout << "1/1";
    }else{
        while(1){
            bound = diag*(diag+1)/2;
            if(n<=bound){
                break;
            }else{
                diag++;
            }
        }
        int diff = bound - n;
        if(diag%2==0){
            cout << diag-diff << "/" << 1+diff;
        }
        else{
            cout << 1+diff << "/" << diag-diff;
        }
    }
    return 0;
}