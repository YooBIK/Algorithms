#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];




int main(){
    int n;
    cin>>n;
    arr[2] = 1;
    arr[3] = 1;
    for(int i=4;i<=n;i++){
        if(i%2 != 0 && i%3 != 0){
            arr[i] = arr[i-1] + 1;
            continue;
        }

        if(i%2 == 0 && i%3 == 0){
            arr[i] = min({arr[i-1],arr[i/2],arr[i/3]}) + 1;
            continue;
        }else if(i%2==0){
            arr[i] = min(arr[i-1],arr[i/2]) + 1;
        }else{
            arr[i] = min(arr[i-1],arr[i/3]) + 1;
        }



    }
    cout << arr[n] ;
    return 0;
}