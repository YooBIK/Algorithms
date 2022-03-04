#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[41]={0,};
vector<pair<int,int>> vec;

int fib(int n){
    if(n==0){
        arr[0]=0;
        return 0;
    }else if(n==1){
        arr[1]=1;
        return 1;
    }
    if(arr[n]!=0){
        return arr[n];
    }else{
        arr[n] = fib(n-1)+fib(n-2);
        return arr[n];
    }
}

int main(){
    arr[0] = 0;
    arr[1] = 1;
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        fib(n);
        if(n==0){
            cout << 1 << " " << 0 << "\n";
        }else if(n==1){
            cout << 0 << " " << 1 << "\n";
        }
        else{
            fib(n);
            cout << arr[n-1] << " " << arr[n] << "\n";
        }
    }
    return 0;

}