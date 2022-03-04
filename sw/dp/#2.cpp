#include <iostream>
#include <algorithm>
using namespace std;

int arr[30001] = {0,};

int main(){
    int n;
    cin >> n;
    for(int i=2;i<=n;i++){
        arr[i]=arr[i-1]+1;

        if(i%2==0){
            arr[i]=min(arr[i-1]+1,arr[i/2]+1);
        }
        if(i%3==0){
            arr[i]=min(arr[i-1]+1,arr[i/3]+1);
        }
        if(i%5==0){
            arr[i]= min(arr[i-1]+1,arr[i/5]+1);
        }

    }
    cout << arr[n];
    return 0;
}