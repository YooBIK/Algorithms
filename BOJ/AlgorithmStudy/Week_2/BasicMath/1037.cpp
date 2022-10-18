#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> vec;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }

    sort(vec.begin(),vec.end());
    int result = vec[0]*vec[vec.size()-1];
    cout << result;
    return 0;

}