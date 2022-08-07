#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
string str;
bool visit[10];
vector<vector<int>> result;
vector<int> temp;

void dfs(int num){
    if(num == n+1){
        result.push_back(temp);
        return;
    }

    for(int i=0;i<=9;i++){
        if(!visit[i]){
            if((str[num-1] == '<' && temp[num-1] < i) || (str[num-1] == '>' && temp[num-1] > i) ){
                temp.push_back(i);
                visit[i] = true;
                dfs(num+1);
                temp.pop_back();
                visit[i]=false;
            }
        }
    }
}



int main(){

    cin >> n;
    for(int i=0;i<n;i++){
        char x;
        cin >> x;
        str.push_back(x);
    }

    for(int i=0;i<=9;i++){
        temp.push_back(i);
        visit[i]= true;
        dfs(1);
        temp.clear();
        for(int j=0;j<10;j++){
            visit[j] = false;
        }
    }

    sort(result.begin(),result.end());
    for(int i=0;i<result[result.size()-1].size();i++){
        cout << result[result.size()-1][i];
    }
    cout << "\n";

    for(int i=0;i<result[0].size();i++){
        cout << result[0][i];
    }
    return 0;
}