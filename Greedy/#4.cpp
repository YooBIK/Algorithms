#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,k;
    cin >> n>>k;
    int count=0;
    while(n!=1){
        if(n%k==0){
            n/=k;
        }else{
            n--;
        }
        count++;
    }
    cout << count;
    return 0;
}