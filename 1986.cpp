#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;

queue<pair<int,int>> queens;
queue<pair<int,int>> knights;

int chess[1001][1001] = {0,};
int check_safe[1001][1001] = {0,};
int queen_dir_row[8] = {-1,-1,-1,0,1,1,1,0};
int queen_dir_col[8] = {-1,0,1,1,1,0,-1,-1};
int knight_dir_row[8] = {-2,-1,-2,-1,1,2,2,1};
int knight_dir_col[8] = {-1,-2,1,2,2,1,-1,-2};

void check_knights(){
    while(!knights.empty()){
        int row = knights.front().first;
        int col = knights.front().second;
        check_safe[row][col] = 1;
        knights.pop();
        for(int i=0;i<8;i++){
            int n_row = row + knight_dir_row[i];
            int n_col = col + knight_dir_col[i];
            if(n_row >=1 && n_row <= n && n_col >= 1 && n_col <=m && chess[n_row][n_col] == 0){
                check_safe[n_row][n_col] = 1;
            }
        }
    }
}

void check_queens(){
    while(!queens.empty()){
        int row = queens.front().first;
        int col = queens.front().second;
        check_safe[row][col] = 1;
        queens.pop();
        for(int i=0;i<8;i++){
            int n_row = row + queen_dir_row[i];
            int n_col = col + queen_dir_col[i];
            while(1){
                if(n_row>=1 && n_row<=n && n_col>=1 && n_col <= m && chess[n_row][n_col] == 0){
                    check_safe[n_row][n_col] = 1;
                    n_row = n_row + queen_dir_row[i];
                    n_col = n_col + queen_dir_col[i];
                }else{
                    break;
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<3;i++){
        int num;
        cin >> num;
        for(int j=0;j<num;j++){
            int row,col;
            cin >> row >> col;
            chess[row][col] = 1;
            check_safe[row][col] = 1;
            if(i==0){
                queens.push({row,col});
            }else if(i==1){
                knights.push({row,col});
            }
        }
    }

    check_knights();
    check_queens();

    int result =0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(check_safe[i][j]==0){
                result++;
            }
        }
    }
    cout << result;

    return 0;
}