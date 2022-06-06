#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


string map[20];

int dir_x[4] = {1,0,-1,0};
int dir_y[4] = {0,1,0,-1};

int r,c;

int alpha[26] = {0,};
int result = -1;


void dfs(int x,int y,int cnt){
    result = max(cnt,result);

    for(int i=0;i<4;i++){
        int nx = x + dir_x[i];
        int ny = y + dir_y[i];
        
        if(nx>=0&&nx<r&&ny>=0&&ny<c){
            if(alpha[map[nx][ny]-'A']==0){
                alpha[map[nx][ny]-'A'] = 1;
                dfs(nx,ny,cnt+1);
                alpha[map[nx][ny]-'A']=0;
            }
        }
    }
}


int main(){
    cin >> r>>c;
    for(int i=0;i<r;i++){
        cin >> map[i];
    }

    alpha[map[0][0]-'A'] = 1;
    dfs(0,0,1);
    cout << result;
    return 0;
}