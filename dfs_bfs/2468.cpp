#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int map[100][100] = {0,};
int visited[100][100] = {0,};

int dir_x[4] = {1,0,-1,0};
int dir_y[4] = {0,1,0,-1};


void dfs(int height, int x, int y){
    visited[x][y] = 1;
    for(int i=0;i<4;i++){
        int nx = x + dir_x[i];
        int ny = y + dir_y[i];
        if(nx>=0 && nx < 100 && ny >=0 && ny < 100 && map[nx][ny]> height && visited[nx][ny]==0){
            visited[nx][ny]=1;
            dfs(height,nx,ny);
        }


    }
}

void init(){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            visited[i][j] = 0;
        }
    }
}

int main(){
    cin >> n;
    int result = -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
        }
    }
    vector<int> vec;

    for(int height=0;height<=100;height++){
        int count = 0 ;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==0 && map[i][j]>height){
                    count++;
                    dfs(height,i,j);
                }
            }
        }
        if(count > result){
            result = count;
        }
        init();
    }
    cout << result;
    return 0;
}