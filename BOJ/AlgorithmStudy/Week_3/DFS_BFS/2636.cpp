#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int arr[100][100]={0,};
int visit[100][100]={0,};

// 공기인지 먼저 bfs
// 이후 치즈들 bfs해서 덩어리 확인
// 덩어리들이 공기랑 접해있는 부분 체크하고 제거
//  1시간 지나면서 visit 업데이트 & 접해있는 부분 제거
  

int dir_row[4]={0,1,0,-1};
int dir_col[4]={1,0,-1,0};

int n,m;

void bfs_cheese(int r, int c){
    queue<pair<int,int>> q_cheese;
    q_cheese.push({r,c});
    visit[r][c] = 1;
    while(!q_cheese.empty()){
        int c_row = q_cheese.front().first; 
        int c_col = q_cheese.front().second;
        q_cheese.pop();
        for(int i=0;i<4;i++){
            int n_row = c_row + dir_row[i];
            int n_col = c_col + dir_col[i];
            if(n_row > 0 && n_row < n-1 && n_col > 0 && n_col < m-1 && arr[n_row][n_col] == 1 && !visit[n_row][n_col]){
                q_cheese.push({n_row,n_col});
                visit[n_row][n_col] = 1;
            }
        }
    }   
}

void bfs_air(int r, int c){
    queue<pair<int,int>> q_air;
    q_air.push({r,c});
    visit[r][c] = -1;
    while(!q_air.empty()){
        int c_row = q_air.front().first; 
        int c_col = q_air.front().second;
        q_air.pop();
        for(int i=0;i<4;i++){
            int n_row = c_row + dir_row[i];
            int n_col = c_col + dir_col[i];
            if(n_row >= 0 && n_row < n && n_col >= 0 && n_col < m && arr[n_row][n_col] == 0 && visit[n_row][n_col]==0){
                q_air.push({n_row,n_col});
                visit[n_row][n_col] = -1;
            }
        }
    }
}

bool checker(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1){
                return true;
            }
        }
    }
    return false;
}

int counter(){
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    
    vector<pair<int,int>> vec;
    int sec = 0;
    vec.push_back({sec,counter()});
    while(checker()){
        sec++;
        bfs_air(0,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==1 && visit[i][j]==0){
                    bfs_cheese(i,j);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==1){
                    for(int k=0;k<4;k++){
                        int n_row = i+dir_row[k];
                        int n_col = j+dir_col[k];
                        if(n_row >=0 && n_row < n && n_col >=0 && n_col < m && visit[n_row][n_col]== -1 && arr[i][j] == 1){
                            arr[i][j]=0;
                        }
                    }    
                }
            }
        }
        vec.push_back({sec,counter()});

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                visit[i][j] = 0;
            }
        }
    }
    cout << vec[vec.size()-1].first << "\n" << vec[vec.size()-2].second << "\n";
    return 0;
}