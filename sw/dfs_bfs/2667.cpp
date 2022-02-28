#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n;
int cnt=0;
string map[25];
int visited[25][25]= {0,};

int dir_x[4] = {1,0,-1,0};
int dir_y[4] = {0,1,0,-1};

void bfs(int x, int y){
    visited[x][y] = 1;
    queue<pair<int,int>> q;
    cnt++;
    q.push({x,y});
    while(!q.empty()){
        int xx = q.front().first; 
        int yy = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int dx = xx + dir_x[i];
            int dy = yy + dir_y[i];
            if(dx>=0 && dx < n && dy >=0 && dy<n && map[dx][dy]== '1'  && visited[dx][dy]== 0){
                q.push({dx,dy});
                visited[dx][dy] = 1;
                cnt ++;
            }
        }
    }
}

int main(){
    vector<int> vec;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> map[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]=='1' && visited[i][j]==0){
                cnt = 0;
                bfs(i,j);
                vec.push_back(cnt);
            }
        }
    }

    sort(vec.begin(),vec.end());

    cout << vec.size() << "\n";
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << "\n";
    }
    return 0;
}