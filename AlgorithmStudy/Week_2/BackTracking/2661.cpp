#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
string str;
bool visit[81];
vector<string> result;
bool flag = false;

bool is_possible(int x){
    string temp = str;
    temp.push_back(x+'0');

    for(int i=1;i<=temp.length()/2;i++){
        if(temp.substr(temp.size()-i) == temp.substr(temp.size()-i-i, i)){
            return false;
        }
    }
    return true;
}

void dfs(int num){
    if(num==n){
        cout << str;
        flag = true;
        return ;
    }

    for(int i=1;i<=3;i++){
        if(flag) return ;
        if(!visit[num] && is_possible(i)){
            visit[num] = true;
            str.push_back(i+'0');
            dfs(num+1);
            visit[num] = false;
            str.pop_back();
        }
    }

}

int main(){
    cin >> n;
    dfs(0);
    cout << str;

    return 0;
}