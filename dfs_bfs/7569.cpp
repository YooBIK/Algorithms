#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int map[100][100][100] = {0,};
int date[100][100][100] = {0,};
int n,m,h;
int result =0 ;

int dir_x[6] = {1,0,-1,0,0,0};
int dir_y[6] = {0,1,0,-1,0,0};
int dir_z[6] = {0,0,0,0,1,-1};

class three{
    public:
    int x,y,z;
    three(int x,int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

queue<three> q;

void bfs(){
    while(!q.empty()){
        int xx,yy,zz;
        xx = q.front().x;
        yy = q.front().y;
        zz = q.front().z;
        q.pop();
        for(int i=0;i<6;i++){
            int nx = xx + dir_x[i];
            int ny = yy + dir_y[i];
            int nz = zz + dir_z[i];
            if(nx>=0 && nx < m && ny >=0 && ny < n && nz >=0 && nz<h  && map[nx][ny][nz]==0){
                q.push(three(nx,ny,nz));
                map[nx][ny][nz] = map[xx][yy][zz]+1;
            }

        }
    }
}

int main(){
    cin >> m >> n >> h;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin >> map[k][j][i];
                if(map[k][j][i]==1){
                    q.push(three(k,j,i));
                }
            }
        }
    }
    bfs();
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(map[k][j][i]==0){
                   cout << -1;
                   return 0;
                }
                if(result<map[k][j][i]){
                    result = map[k][j][i];
                }
            }
        }
    }
    cout << result -1;
    return 0;
}