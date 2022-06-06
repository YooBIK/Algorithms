#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,string> a,pair<int,string>b){
    return a.first<b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >>n;
    vector<pair<int,string>> vec;
    for(int i=0;i<n;i++){
        int x;
        string str;
        cin >> x;
        cin >> str;
        vec.push_back(make_pair(x,str));
    }
    stable_sort(vec.begin(),vec.end(),compare);
    for(int i=0;i<vec.size();i++){
        cout << vec[i].first << " " << vec[i].second << "\n";
    }
    return 0;
}