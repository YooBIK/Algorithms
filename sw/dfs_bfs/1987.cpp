#include<iostream>
#include <queue>
#include <vector>
using namespace std;

string map[20];
int visit[20][20] = {0,};

int dir_x[4] = {1,0,-1,0};
int dir_y[4] = {0,1,0,-1};

int r,c;

vector<char> vec;
int count =0;


void dfs(int x,int y){
    visit[x][y] =1;
    for(int i=0;i<4;i++){
        int nx = x + dir_x[i];
        int ny = y + dir_y[i];
        int flag = 0;
        
        if(nx>=0&&nx<20&&ny>=0&&ny<20&&visit[nx][ny]==0){
            for(int j=0;j<vec.size();j++){
                if(map[nx][ny]==vec[j]){
                    flag=1;
                }
            }
            if(flag==0){
                vec.push_back(map[nx][ny]);
                visit[nx][ny]=1;
                count++;
                dfs(nx,ny);
            }
        }
    }
}

int main(){
    cin >> r>>c;
    for(int i=0;i<r;i++){
        cin >> map[i];
    }
    vec.push_back(map[0][0]);
    dfs(0,0);
    cout << count;
    return 0;
}