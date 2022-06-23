#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int t,w,h;
string map[1001];
int cnt[1001][1001] = {0,};

int dir_x[4] = {1,0,-1,0};
int dir_y[4] = {0,1,0,-1};

queue<pair<int,int>> human_q;
queue<pair<int,int>> fire_q;
vector<int> answer;
int result = 0;


void init(){
    result = 0;
    for(int i=0;i<1001;i++){
        map[i].clear();
        for(int j=0;j<1001;j++){
            cnt[i][j]=0;
        }
    }
    while(!human_q.empty()) human_q.pop();
    while(!fire_q.empty()) fire_q.pop();
}

void bfs(int x, int y){
    cnt[x][y] =1;
    human_q.push({x,y});
    while(!human_q.empty()){
        int x1 = human_q.front().first;
        int y1 = human_q.front().second;
        human_q.pop();
        if(x1 == 0 || x1 == w || y1 == 0 || y1 == h){
            result = cnt[x1][y1];
            break;
        }
        
        for(int i=0;i<fire_q.size();i++){
            for(int i=0;i<4;i++){
                int fire_nx = fire_q.front().first + dir_x[i];
                int fire_ny = fire_q.front().second + dir_y[i];
                fire_q.pop();
                if(fire_nx>=0 && fire_nx <= w && fire_ny >=0 && fire_ny <= h && map[fire_nx][fire_ny] != '#'){
                    map[fire_nx][fire_ny] = '*';
                    fire_q.push({fire_nx,fire_ny});
                } 
            }
        }
        
        for(int i=0;i<4;i++){
            int dx = x1+dir_x[i];
            int dy = y1+dir_y[i];
            if(dx>=0 && dx <= w && dy>=0 && dy < h && cnt[dx][dy]==0 && map[dx][dy] =='.'){
                human_q.push({dx,dy});
                cnt[dx][dy] = cnt[x1][y1]+1;
            }
        }
    }
}

int main(){
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> w >> h;
        pair<int,int> pos;
        for(int j=0;j<h;j++){
            cin >> map[j];
            for(int k=0;k<w;k++){
                if(map[j][k]=='@'){
                    pos = {k,j};
                }
                if(map[j][k]=='*'){
                    fire_q.push({k,j});
                }
            }
        }
        bfs(pos.first, pos.second);
    }
    
}