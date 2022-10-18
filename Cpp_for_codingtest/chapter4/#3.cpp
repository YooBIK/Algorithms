#include <iostream>
using namespace std;
int map[50][50];
int route[50][50];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    int n,m;
    cin >> n >> m;
    int row,col,dir;
    cin >> row >> col >> dir;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    int result=1;
    route[row][col]=1;
    int turn =0;
    while(1){
        if(dir==0){
            dir =3;
        }else{
            dir--;
        }
        int newrow = row + dx[dir];
        int newcol = col + dy[dir];        
        if(map[newrow][newcol]==0&&route[newrow][newcol]==0){
            route[newrow][newcol]=1;
            row = newrow;
            col = newcol;
            result++;
            turn =0;
            continue;
            
        }else{
            turn++;
        }
        if(turn==4){
            newrow = row - dx[dir];
            newcol = col - dy[dir];  
            if(map[newrow][newcol]==0){
                row = newrow;
                col = newcol;
            }else{
                break;
            }
            turn=0;
        }
    }
    cout << result;
    return 0;
}