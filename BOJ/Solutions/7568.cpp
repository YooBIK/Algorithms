#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> vec;
    vector<int> rank;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        pair<int,int> p = make_pair(x,y);
        vec.push_back(p);
    }
    for(int i=0;i<vec.size();i++){
        int count =0;
        for(int j=0;j<vec.size();j++){
            if(vec[i].first<vec[j].first && vec[i].second < vec[j].second){
                count++;
            }
        }
        rank.push_back(count+1);
    }
    for(int i=0;i<rank.size();i++){
        cout << rank[i] << " ";
    }
    return 0;

}