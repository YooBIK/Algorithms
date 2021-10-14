#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,k;
    int result=0;
    vector<int> arr;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    for(int i=n-1;i>=0;i--){
        if(k>=arr[i]){
            result+=k/arr[i];
            k=k%arr[i];
        }
        if(k==0){
            break;
        }
    }
    cout << result;
    return 0;
}