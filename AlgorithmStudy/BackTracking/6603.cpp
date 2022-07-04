#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k;

vector<int> temp;
vector<int> num_list;
vector<bool> visit;
vector<vector<int>> result;

void dfs_conb(int start,int num){
    if(num==6){
        sort(temp.begin(),temp.end());
        result.push_back(temp);
        return;
    }

    for(int i=start;i<num_list.size();i++){
        if(!visit[i]){
            temp.push_back(num_list[i]);
            visit[i] = true;
            dfs_conb(i,num+1);
            visit[i] = false;
            temp.pop_back();
        }
    }
}

void init(){
    temp.clear();
    result.clear();
    num_list.clear();
    for(int i=0;i<14;i++){
        visit[i]=false;
    }
}

void print_result(){
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(){
    
    while(1){
        cin >> k;
        if(k==0 || k<=6 || k >= 13) break;
        for(int i=0;i<k;i++){
            int x;
            cin >> x;
            num_list.push_back(x);
            visit.push_back(false);
        }
        dfs_conb(0,0);
        print_result();
        init();
    }
    return 0;
}