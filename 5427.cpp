#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int t,w,h;
string map[1001];
int cnt[1001][1001] = {0,};

int dir_x[4] = {1,0,-1,0};
int dir_y[4] = {0,1,0,-1};

queue<pair<int,int>> human_q;
queue<pair<int,int>> fire_q;



void init(){
    for(int i=0;i<1001;i++){
        map[i].clear();
        for(int j=0;j<1001;j++){
            cnt[i][j]=0;
        }
    }
    while(!human_q.empty()) human_q.pop();
    while(!fire_q.empty()) fire_q.pop();
}

int bfs(int row, int col){
    int flag = 0;
    cnt[row][col] =1;
    human_q.push({row,col});
    while(!human_q.empty()){
        int fire_q_size = fire_q.size();
        for(int i=0;i<fire_q_size;i++){
            int fire_c_row = fire_q.front().first;
            int fire_c_col = fire_q.front().second;
            fire_q.pop();
            for(int j=0;j<4;j++){
                int fire_n_row = fire_c_row + dir_x[j];
                int fire_n_col = fire_c_col + dir_y[j];
                if(fire_n_row>=0 && fire_n_row < h && fire_n_col >=0 && fire_n_col < w ){
                    if(map[fire_n_row][fire_n_col] =='.' || map[fire_n_row][fire_n_col] == '@'){
                        map[fire_n_row][fire_n_col] = '*';
                        fire_q.push({fire_n_row,fire_n_col});
                    }

                } 
            }
        }

        
        int human_q_size = human_q.size();
        for(int i=0;i<human_q_size;i++){
            int c_row = human_q.front().first;
            int c_col = human_q.front().second;
            human_q.pop();

            if(c_row == 0 || c_row == h-1 || c_col == 0 || c_col == w-1){
                return cnt[c_row][c_col];
            }

            for(int j=0;j<4;j++){
                int n_row = c_row+ dir_x[j];
                int n_col = c_col+ dir_y[j];
                if(n_row>=0 && n_row < h && n_col >= 0 && n_col < w && cnt[n_row][n_col]==0 && map[n_row][n_col] =='.'){
                   human_q.push({n_row,n_col});
                   cnt[n_row][n_col] = cnt[c_row][c_col] + 1;
                }
            }
        }
    }

    return -1;
}

int main(){
    cin >> t;
    for(int i=0;i<t;i++){
        init();
        cin >> w >> h;
        pair<int,int> pos;
        for(int j=0;j<h;j++){
            cin >> map[j];
            for(int k=0;k<w;k++){
                if(map[j][k]=='@'){
                    pos = {j,k};
                }
                if(map[j][k]=='*'){
                    fire_q.push({j,k});
                }
            }
        }
        int result = bfs(pos.first, pos.second);
        if(result == -1){
            cout << "IMPOSSIBLE" << "\n";
        }else{
            cout << result << "\n"; 
        }
    }

    return 0;
    
}