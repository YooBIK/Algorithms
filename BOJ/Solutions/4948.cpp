#include <iostream>
#include <cmath>
using namespace std;

int main(){
    while(1){
        int n;
        cin >> n;
        if(n==0){
            break;
        }
        else{
            bool* arr = new bool[2*n+1];
            int count=0;
            arr[0]=false;
            arr[1]=false;
            for(int i=2;i<=2*n;i++){
                arr[i]=true;
            }
            for(int i=2;i<=2*n;i++){
                if(arr[i]){
                    for(int j=2*i;j<=2*n;j+=i){
                        arr[j]=false;
                    }
                }
            }
            for(int i=n+1;i<=2*n;i++){
                if(arr[i]){
                    count++;
                }
            }
            cout << count << "\n";
            delete[] arr;
        }
    }
    return 0;
}