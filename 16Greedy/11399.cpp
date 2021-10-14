#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    vector<int> arr;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >>x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    int result=0;
    for(int i=0;i<n;i++){
        result += (n-i)*arr[i];
    }
    cout <<result;
    return 0;
}