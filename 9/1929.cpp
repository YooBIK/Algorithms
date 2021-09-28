#include <iostream>
#include <vector>
using namespace std;

int main(){
    int m,n;
    cin >> m>>n;
    bool* arr = new bool[n+1];
    arr[0],arr[1]=false;
    for(int i=2;i<n+1;i++){
        arr[i]=true;
    }
    for(int i=2;i<=n;i++){
        if(arr[i]){
            for(int j=i*2;j<=n;j+=i){
                arr[j]=false;
            }
        }
    }
    for(int i=m;i<=n;i++){
        if(arr[i]){
            cout << i << "\n";
        }
    }
    return 0;
}