#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N,M;
string map[100];
int cnt[100][100] = {0,};

int dir_x[4] = {1,0,-1,0};
int dir_y[4] = {0,1,0,-1};


void bfs(int x, int y){
    cnt[x][y] =1;
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        int x1 = q.front().first;
        int y1 = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int dx = x1+dir_x[i];
            int dy = y1+dir_y[i];
            if(dx>=0 && dx <N && dy>=0 && dy < M && cnt[dx][dy]==0 && map[dx][dy]=='1'){
                q.push({dx,dy});
                cnt[dx][dy] = cnt[x1][y1]+1;
            }
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> map[i];
    }   

    bfs(0,0);
    cout << cnt[N-1][M-1];
    return 0;

}