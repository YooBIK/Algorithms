#include <iostream>
#include <vector>

using namespace std;

int n;
int map[15][15] = {0,};
int row_check[15] = {0,};
int col_check[15] = {0,};
int cnt = 0;


void marking(int r, int c, int mode){

    for(int i=r;i<n;i++){
        map[r][i] += mode;
        map[i][c] += mode;
        for(int j=0;j<n;j++){
            if((i != r && j != c) && ((i+j==r+c) || (i-j == r-c)) ){
                map[i][j] += mode;
            }
        }
    }
}

void dfs(int row){
    if(row==n){
        cnt++;
        return;
    }

    for(int i=0;i<n;i++){
        if(map[row][i]==0){
            marking(row,i,1);
            dfs(row+1);
            marking(row,i,-1);
        }
    }
}

int main(){
    cin >> n;
    dfs(0);
    cout << cnt;
    return 0;
}