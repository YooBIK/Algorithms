#include <iostream>
using namespace std;
int map[50][50];
int route[50][50];

int main(){
    int n,m;
    cin >> n >> m; // n = row , m= col
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
        int newrow,newcol;
        switch(dir){
            case 0:
                newrow = row--; 
                break;         
            case 1:
                newcol = col++;
                break;
            case 2:
                newrow = row++;
                break;
            case 3:
                newcol = col--;
                break;
            default:
                break;
        }
        if(map[newrow][newcol]==0&&route[newrow][newcol]==0){
            route[row][col]=1;
            row = newrow;
            col = newcol;
            result++;
            turn =0;
            continue;
            
        }else{
            turn++;
        }
        if(turn==4){
            switch(dir){
                case 0:
                    newrow = row++; 
                    break;         
                case 1:
                    newcol = col--;
                    break;
                case 2:
                    newrow = row--;
                    break;
                case 3:
                    newcol = col++;
                    break;
                default:
                    break;
            }
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