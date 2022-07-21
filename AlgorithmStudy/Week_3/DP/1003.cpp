#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t;

vector<pair<int,int>> vec;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;

    vec.push_back({1,0});
    vec.push_back({0,1});

    for(int i=2;i<=40;i++){
        pair<int,int> p;
        p.first = vec[i-1].first + vec[i-2].first;
        p.second= vec[i-1].second + vec[i-2].second;
        vec.push_back(p);
    }

    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        cout << vec[n].first << " " << vec[n].second << "\n";
    }
    return 0;
}