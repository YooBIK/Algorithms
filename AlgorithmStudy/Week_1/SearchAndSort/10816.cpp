#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n,m;
vector<int> result;
unordered_map<int,int> map;


int main(){
    cin >> n; 
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        map[x]++;
    }
    
    cin >> m;
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        result.push_back(map[x]);
    }

    for(int i=0;i<result.size();i++){
        cout << result[i] << " ";
    }
    return 0;
}