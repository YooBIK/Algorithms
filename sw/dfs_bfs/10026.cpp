#include <iostream>
using namespace std;

string map[100];
int visited_n[100][100] = {0,};
int visited_abn[100][100] = {0,};


int dir_x[4] = {1,0,-1,0};
int dir_y[4] = {0,1,0,-1};

void dfs_n(int x, int y){
    visited_n[x][y]=1;
    for(int i=0;i<4;i++){
        int nx = x + dir_x[i];
        int ny = y + dir_y[i];
        if( nx>=0 && nx < 100 && ny >=0 && ny < 100 && map[nx][ny] == map[x][y] && visited_n[nx][ny]==0){
            visited_n[nx][ny]=1;
            dfs_n(nx,ny);
        }
    }
}

void dfs_abn(int x, int y){
    visited_abn[x][y]=1;
    for(int i=0;i<4;i++){
        int nx = x+dir_x[i];
        int ny = y+dir_y[i];
        if( nx < 100 && nx >=0 && ny >=0 && ny < 100 && visited_abn[nx][ny]==0 &&  map[nx][ny] == map[x][y]){
            visited_abn[nx][ny]=1;
            dfs_abn(nx,ny);
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> map[i];
    }
    int cnt1 = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited_n[i][j]==0){
                dfs_n(i,j);
                cnt1++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]=='G'){
                map[i][j]='R';
            }
        }
    }
    int cnt2=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited_abn[i][j]==0){
                dfs_abn(i,j);
                cnt2++;
            }
        }
    }
    cout << cnt1 << " " << cnt2;
    return 0;

}