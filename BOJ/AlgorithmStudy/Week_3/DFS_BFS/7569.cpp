#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n,m,h;

int arr[100][100][100];
int visit[100][100][100];

int dir_x[6] = {0,1,0,-1,0,0}; 
int dir_y[6] = {1,0,-1,0,0,0};
int dir_z[6] = {0,0,0,0,1,-1};

class tomato{
    public:
    tomato(int a,int b, int c){
        x= a;
        y= b;
        z= c;
    }
    int x;
    int y;
    int z;
};


queue<tomato> q;

void bfs(){

    while(!q.empty()){
        int cur_x= q.front().x;
        int cur_y =q.front().y;
        int cur_z= q.front().z;
        q.pop();
        for(int i=0;i<6;i++){
            int nx = cur_x+dir_x[i];
            int ny = cur_y+dir_y[i];
            int nz = cur_z+dir_z[i];
            if(nx >= 0 && ny >= 0 && nz >= 0 && nx < n && ny < m && nz < h && arr[nx][ny][nz]==0 && visit[nx][ny][nz] == 0){
                q.push(tomato(nx,ny,nz));
                arr[nx][ny][nz] = 1;
                visit[nx][ny][nz] = visit[cur_x][cur_y][cur_z] + 1;
            }
        }
    }
}



int main(){
    cin >> m>> n >> h; 
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin >> arr[j][k][i];
                if(arr[j][k][i] == 1){
                    q.push(tomato(j,k,i));
                }
            }
        }
    }

    bfs();
    int result =0;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(arr[j][k][i] == 0){
                    cout << -1 ;
                    return 0;
                }
                result = max(result, visit[j][k][i]);
            }
        }
    }
    cout << result;
    return 0;

}