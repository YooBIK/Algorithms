#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int dir_x[8] = {1,2,2,1,-1,-2,-2,-1};
int dir_y[8] = {-2,-1,1,2,2,1,-1,-2};

queue<pair<int,int>> q;
int map[300][300] = {0,};
int visit[300][300] = {0,};
int target_x,target_y;
int cur_x,cur_y;
int map_size;
int move_count=0;
vector<int> vec;

void init(){
    move_count = 0;
    target_x = 0;
    target_y = 0;
    cur_x = 0;
    cur_y = 0;
    for(int i=0;i<300;i++){
        for(int j=0;j<300;j++){
            map[i][j] = 0;

        }
    }
}

void bfs(int x,int y){
    q.push({x,y});
    map[x][y]++;
    while(!q.empty()){
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int nx = xx+dir_x[i];
            int ny = yy+dir_y[i];
            if(nx >=0 && nx <map_size && ny>=0 && ny < map_size && map[nx][ny] == 0 ){
                map[nx][ny]= map[xx][yy]+1;
                q.push({nx,ny});
            }
        }
    }

}

int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> map_size;
        cin >> cur_x >> cur_y >> target_x >> target_y;
        bfs(cur_x,cur_y);
        vec.push_back(map[target_x][target_y]-1);
        init();
    }
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << "\n"; 
    }
}