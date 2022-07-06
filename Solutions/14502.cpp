#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
int n,m;

int map[8][8] = {0,};
int temp[8][8] = {0,};

int dir_x[4] = {0,1,0,-1};
int dir_y[4] = {-1,0,1,0};
int result =0;

queue<pair<int,int>> q;

int count_area(){
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(temp[i][j]==0){
                cnt++;
            }
        }
    }
    return cnt;
}

void bfs(){
    int arr[8][8] = {0,};   //이걸 왜 써야하지?
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j] = temp[i][j];
            if(temp[i][j]==2){
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = xx + dir_x[i];
            int ny = yy + dir_y[i];
            if(nx >=0 && nx <n && ny >=0 && ny < m && arr[nx][ny]==0){
                arr[nx][ny] = 2;
                q.push({nx,ny});
            }
        }
    }
    int cnt =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                cnt++;
            }
        }
    }
    result = max(result,cnt);
}

void copy_map(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            temp[i][j] = map[i][j];
        }
    }
}

void wall(int cnt){
    if(cnt == 3){
        bfs();
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(temp[i][j]==0){
                temp[i][j] =1;
                wall(cnt+1);
                temp[i][j] = 0;
            }
        }
    }
}



int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]==0){
                copy_map();
                temp[i][j] = 1;
                wall(1);
                temp[i][j] = 0;
            }
        }
    }
    cout << result;
    return 0;
}