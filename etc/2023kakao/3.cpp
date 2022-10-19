#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


vector<int> temp;
vector<vector<int>> vec;
void dfs(int cur, vector<int> &emoticons){

    if(cur == emoticons.size()){
        vec.push_back(temp);
        return;
    }

    for(int i=1;i<=4;i++){
        int percent = i*10;
        temp.push_back(percent);
        dfs(cur+1, emoticons);
        temp.pop_back();
    }
}

bool compare(pair<int,int> a ,pair<int,int> b){
    if(a.first == b.first){
        return a.second> b.second;
    }else{
        return a.first>b.first;
    }

}


vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    vector<pair<int,int>> ans;
    dfs(0,emoticons);

    for(int i=0;i<vec.size();i++){
        int user = 0;
        int totalCost = 0;
        for(int j=0;j<users.size();j++){
            int cost = 0;
            for(int k=0;k<vec[i].size();k++){
                if(users[j][0]<=vec[i][k]){
                    cost += emoticons[k] * (100- vec[i][k]) / 100;
                }
            }
            if(cost > users[j][1]){
                user++;
            }else{
                totalCost += cost;
            }
        }
        cout << user << " " << totalCost << "\n";
        pair<int,int> status = {user,totalCost};
        ans.push_back(status);
    }
    sort(ans.begin(),ans.end(),compare);
    answer.push_back(ans[0].first);
    answer.push_back(ans[0].second);
    return answer;
}