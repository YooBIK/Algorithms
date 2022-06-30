#include <iostream>
#include <algorithm>
#include <vector>

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
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << " ";
    }
    return 0;
}