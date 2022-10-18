#include <iostream>

using namespace std;


int n,m;

int arr[1000001] = {0,}; // arr[i] == 0 이면 소수 

int main(){
    cin >> m >> n ;
    arr[0] = 1;
    arr[1] = 1;

    for(int i=0;i*i<=n;i++){
        if(arr[i]==0){
            for(int j=i*2;j<=n;j+=i){
                arr[j] = 1;
            }
        }
    }
    for(int i=m;i<=n;i++){
        if(arr[i]==0){
            cout << i << "\n";
        }
    }
    return 0;
}