#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int map[50][50] = {0,};
int visit[50][50] = {0,};

int dir_x[4] = {1,0,-1,0};
int dir_y[4] = {0,1,0,-1};



int n,m,k;

void bfs(int x,int y){
    visit[x][y]=1;
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        int x1 = q.front().first;
        int y1 = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int dx = x1 + dir_x[i];
            int dy = y1 + dir_y[i];
            if(dx >= 0 && dx < n && dy >= 0 && dy < m && visit[dx][dy]==0 && map[dx][dy]==1 ){
                q.push({dx,dy});
                visit[dx][dy] = 1;
            }
        }
    }
}

void init(){
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            map[i][j] = 0;
            visit[i][j] = 0;
        }
    }
}

int main(){
    vector<int> vec;
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        init();
        cin >> n >> m >> k;
        for(int j=0;j<k;j++){
            int x,y;
            cin >> x >> y;
            map[x][y] = 1;
        }
        int cnt =0;
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                if(map[a][b]==1 && visit[a][b]==0){
                    bfs(a,b);
                    cnt++;
                }
            }
        }
        vec.push_back(cnt);
        
    }
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << "\n";
    }
    return 0;
}