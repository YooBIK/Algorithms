#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

queue<pair<int,int>> snake;
int map[101][101];
vector<pair<int,char>> turninfo;
int d_row[] = {0,1,0,-1}; // 동 남 서 북 
int d_col[] = {1,0,-1,0};

int turning(int dir, char c){
    if(c=='L'){
        if(dir==0){
            dir=3;
        }else{
            dir--;
        }
    }else{
        dir = (dir+1)%4;
    }
    return dir;
}


int main(){
    int n,k,l;
    cin >> n;
    cin >> k;
    for(int i=0;i<k;i++){
        int row,col;
        cin >> row >> col;
        map[row][col] = 1;
    }
    cin >> l;
    for(int i=0;i<l;i++){
        int x;
        char c;
        cin >> x >> c;
        turninfo.push_back(make_pair(x,c));
    }



    map[1][1]==2;
    snake.push(make_pair(1,1));
    int head_row = 1, head_col = 1;
    int index=0;
    int currenttime = 0;
    int dir = 0;


    while(1){
        int newrow = head_row+ d_row[dir];
        int newcol = head_col+ d_col[dir];
        if(newrow>=1&&newrow<=n&&newcol>=1&&newcol<=n&&map[newrow][newcol]!=2){
            map[newrow][newcol]=2;
            snake.push(make_pair(newrow,newcol));
            if(map[newrow][newcol]==0){          
                int tail_row = snake.front().first;
                int tail_col = snake.front().second;
                snake.pop();
                map[tail_row][tail_col]=0;
            } 

        }else{
            currenttime++;
            break;
        }
        head_row = newrow;
        head_col = newcol;
        currenttime++;
        if(turninfo[index].first == currenttime){
            dir = turning(dir,turninfo[index].second);
            index++;
        }
    }
    cout << currenttime;
    
    return 0;
}