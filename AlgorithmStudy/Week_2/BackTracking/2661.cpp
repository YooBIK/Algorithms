#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
string str;
bool visit[81];
vector<string> result;

bool is_possible(int x){
    string temp = str;
    string checker; 
    bool flag = true;
    checker.push_back(x+'0');
    
}

void dfs(int num){
    if(num==n){
        result.push_back(str);
        return ;
    }

    for(int i=1;i<=3;i++){
        if(!visit[num]){
            if(is_possible(i)){
                visit[num] = true;
                str.push_back(i+'0');
                dfs(num+1);
                visit[num] = false;
                str.pop_back();
            }
        }
    }

}

int main(){
    cin >> n;
    dfs(0);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}