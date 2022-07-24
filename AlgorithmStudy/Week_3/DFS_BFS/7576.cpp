#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n,m;

int arr[1000][1000];
int visit[1000][1000];

int dir_row[] = {0,1,0,-1};
int dir_col[] = {1,0,-1,0};

queue<pair<int,int>> q;
int result =0;

void bfs(){

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int n_row = row + dir_row[i];
            int n_col = col + dir_col[i];
            if(n_row >=0 && n_row < n && n_col >=0 && n_col < m && arr[n_row][n_col]==0 && visit[n_row][n_col]==0){
                q.push({n_row,n_col});
                arr[n_row][n_col] = 1;
                visit[n_row][n_col] = visit[row][col] + 1;
            }
        }        
    }
}

int main(){
    cin >> m >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
            if(arr[i][j]==1){
                q.push({i,j});
            }
        }
    }
    bfs();
    int result =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                cout << -1;
                return 0;
            }

            result = max(result,visit[i][j]);
        }
    }
    cout << result;
    return 0;
}