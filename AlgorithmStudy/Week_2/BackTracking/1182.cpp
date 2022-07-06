#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int n,s;
int cnt =0;
int max_num;
bool visit[20] ;

vector<vector<int>> result;
vector<int> num_list;
vector<int> temp;

void dfs(int start,int num){
    
    if(num == max_num){
        result.push_back(temp);
        return;
    }

    for(int i=start;i<num_list.size();i++){
        if(!visit[i]){
            temp.push_back(num_list[i]);
            visit[i]=true;
            dfs(i,num+1);
            visit[i]=false;
            temp.pop_back();
        }
    }
}

int main(){
    cin >> n >> s;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        num_list.push_back(x);
    }

    for(int i=1;i<=num_list.size();i++){
        max_num = i;
        dfs(0,0);
    }


    for(int i=0;i<result.size();i++){
        int sum = 0;
        for(int j=0;j<result[i].size();j++){
            sum += result[i][j];
        }
        if(sum==s) cnt++;
    }
    cout << cnt;
    return 0;
}