#include <iostream>
using namespace std;

int main(){
    long long k;
    cin >> k;
    if(k==1){
        cout << "1";
    }else{
        int bound =1;
        int layer=1;
        while(1){
            if(k>bound+layer*6){
                bound += layer*6;
                layer++;
            }else{
                break;
            }
        }
        cout << layer+1; 
    }   
    return 0;
}