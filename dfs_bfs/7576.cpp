#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;

int map[1000][1000] = {0,};

int dir_x[4] = {1,0,-1,0};
int dir_y[4] = {0,1,0,-1};

queue<pair<int,int>> q;

void bfs(){
    while(!q.empty()){
        int x1 = q.front().first;
        int y1 = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int dx = x1 + dir_x[i];
            int dy = y1 + dir_y[i];
            if(dx >= 0 && dx < n && dy >= 0 && dy < m && map[dx][dy]==0 ){
                q.push({dx,dy});
                map[dx][dy] = map[x1][y1]+1;
            }
        }
    }
}

int main(){
    cin >> m >> n;
    int result =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j]; 
            if(map[i][j]==1){
                q.push({i,j});
            }
        }
    }

    bfs();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]==0){
                cout << -1;
                return 0;
            }
            if(result < map[i][j]){
                result = map[i][j];
            }
        }
    }
    cout << result -1;
    return 0;

}