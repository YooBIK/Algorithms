#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

string map[1000];
string temp[1000];
int visit[1000][1000][2];
vector<pair<int,int>> walls;

int dir_row[4] = {-1,0,1,0};
int dir_col[4] = {0,1,0,-1};

int n,m;

void bfs(){
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},0});
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int wall = q.front().second;
        q.pop();
        
        if(row== n-1 && col == m-1){
            cout << visit[row][col][wall] + 1 ;
            return;
        }

        for(int i=0;i<4;i++){
            int n_row = row + dir_row[i];
            int n_col = col + dir_col[i];
            if(n_row>=0 && n_row<n && n_col>=0 && n_col<m){
                if(wall==0 && map[n_row][n_col]=='1'){
                    q.push({{n_row,n_col},1});
                    visit[n_row][n_col][1] = visit[row][col][wall] + 1;
                }else if(map[n_row][n_col] == '0' && visit[n_row][n_col][wall] == 0){
                    q.push({{n_row,n_col},wall});
                    visit[n_row][n_col][wall] = visit[row][col][wall] +1;
                }
            }
        }
    }
    cout << -1 ;
    return ;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> map[i];
        for(int j=0;j<m;j++){
            if(map[i][j]=='1'){
                walls.push_back({i,j});
            }
        }
    }
    bfs();

}