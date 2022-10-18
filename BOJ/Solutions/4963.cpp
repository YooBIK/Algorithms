#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int map[50][50] = {0,};
int visited[50][50] = {0,};

int dir_x[8]={ 0, 1, 1, 1, 0, -1, -1, -1 };
int dir_y[8]={-1, -1, 0, 1, 1, 1, 0, -1 };

int w,h;

void dfs(int x,int y){
    visited[x][y]=1;
    for(int i=0;i<8;i++){
        int nx = x+dir_x[i];
        int ny = y+dir_y[i];

        if(nx >=0 && nx < 50 && ny >=0 && ny < 50 && map[nx][ny]==1 && visited[nx][ny]==0){
            visited[nx][ny] = 1;
            dfs(nx,ny);
        }
    }
    
}
void init(){
    for(int i =0;i<50;i++){
        for(int j=0;j<50;j++){
            map[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

int main(){
    while(1){
        cin >> w >> h;
        if(w==0&&h==0){
            break;
        }
        init();
        int cnt =0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> map[i][j];
            }
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(map[i][j]==1 && visited[i][j]==0){
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        cout << cnt << "\n";

    }
    return 0;
}