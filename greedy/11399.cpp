#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int n;
    vector<int> vec;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(),vec.end());
    int result =0;
    for(int i=0;i<n;i++){
        result += vec[i]*(n-i);
    }
    cout << result;
    return 0;
}