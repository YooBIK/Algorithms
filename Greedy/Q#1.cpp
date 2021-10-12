#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int arr[100000]={0,};
    bool check[100000] ={0,};
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int result = 0;
    int index=0;
    int nmember=0;
    while(index<n){
        nmember++;
        if(nmember>=arr[index]){
            result++;
            nmember=0;
        }
        index++;
    }
    cout << result;
    return 0;    
}