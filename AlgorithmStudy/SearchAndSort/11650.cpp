#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second<b.second;
    }else{
        return a.first<b.first;
    }
}

int n;
vector<pair<int,int>> vec;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        vec.push_back({x,y});
    }
    sort(vec.begin(),vec.end(),compare);
    for(int i=0;i<vec.size();i++){
        cout << vec[i].first << " " << vec[i].second << "\n";
    }
    return 0;

}