#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int a,int b){
    return a>b;
}

int main(){
    int n;
    vector<int> arr1;
    vector<int> arr2;

    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        arr1.push_back(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        arr2.push_back(x);
    }

    int result = 0;
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end(),compare);
    for(int i=0;i<n;i++){
        result += arr1[i]*arr2[i];
    }
    cout << result;
    return 0;
}