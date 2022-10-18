#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;

string map[25];
bool visit[25][25];

int dir_x[4] = {0,1,0,-1};
int dir_y[4] = {1,0,-1,0};

int cnt =0;

void dfs(int row,int col){ 
    cnt++;
    visit[row][col]=true;

    for(int i=0;i<4;i++){
        int n_row = row + dir_x[i];
        int n_col = col + dir_y[i];
        if(n_row>=0 && n_row<n && n_col>=0 && n_col<n && map[n_row][n_col]=='1' && !visit[n_row][n_col]){
            dfs(n_row,n_col);
        }
    }
}


int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> map[i];
    }
    vector<int> result;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]=='1'&& !visit[i][j]){
                dfs(i,j);
                result.push_back(cnt);
                cnt = 0;
            }
        }
    }
    sort(result.begin(),result.end());
    cout << result.size() << "\n";
    for(int i=0;i<result.size();i++){
        cout << result[i] << "\n";
    }

    return 0;
}