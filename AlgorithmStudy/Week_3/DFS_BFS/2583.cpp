#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int arr[100][100];
int visit[100][100];

int dir_row[] = {0,0,1,-1};
int dir_col[] = {1,-1,0,0};

int n,m,k;

int bfs(int r, int c,int no){
    queue<pair<int,int>> q;
    q.push({r,c});
    visit[r][c] = no;

    while(!q.empty()){
        int cur_r = q.front().first;
        int cur_c = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int n_row = cur_r + dir_row[i];
            int n_col = cur_c + dir_col[i];
            if(n_row >=0 && n_row < m && n_col >=0 && n_col < n && arr[n_row][n_col] == 0 && visit[n_row][n_col]==0){
                q.push({n_row,n_col});
                visit[n_row][n_col] = no;    
            }
        }
    }
    int cnt =0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visit[i][j]==no){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n >> k;
    for(int i=0;i<k;i++){
        int s_col,s_row,e_col,e_row;
        cin >> s_col >> s_row >> e_col >> e_row;
        for(int i=s_row;i<e_row;i++){
            for(int j=s_col;j<e_col;j++){
                arr[i][j] = 1;
            }
        }
    }


    int num = 0;
    int cnt = 0;
    vector<int> vec;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == 0 &&!visit[i][j]){
                num++;
                vec.push_back(bfs(i,j,num));
                cnt++;
            }
        }
    }
    sort(vec.begin(),vec.end());
    cout << cnt << "\n";
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << " ";
    }
    return 0;    
}