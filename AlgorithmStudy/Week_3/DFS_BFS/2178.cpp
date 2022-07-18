#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

string map[100];
int visit[100][100];
int dir_row[4]= {0,1,0,-1};
int dir_col[4]= {1,0,-1,0};

int n,m;

void bfs(int row,int col){

    queue<pair<int,int>> q;
    visit[row][col] = 1;
    q.push({row,col});

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int n_row = r + dir_row[i];
            int n_col = c + dir_col[i];
            if(n_row>=0 && n_row<n && n_col >=0 && n_col < m && map[n_row][n_col]== '1' && !visit[n_row][n_col]){
                q.push({n_row,n_col});
                visit[n_row][n_col] = visit[r][c] + 1;
            }
        }
    }

}

int main(){
    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> map[i];
    }
    bfs(0,0);
    cout << visit[n-1][m-1];
    return 0;
}