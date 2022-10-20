#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;


int map[51][51];
int dir_row[4] = {1,0,0,-1};    // down , left , down, up;
int dir_col[4] = {0,-1,1,0};




string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    if( abs ( k - abs(r-x) + abs(c-y))%2 == 1){
        answer = "impossible";
        return answer;
    }

    if(k < abs(r-x) + abs(c-y)){
        answer = "impossible";
        return answer;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            map[i][j]=0;
        }
    }
    map[r][c] = 1;

    queue<pair<pair<int,int>,string>> q;
    q.push({{x,y},""});
    string route;
    while(!q.empty()){
        int cur_row = q.front().first.first;
        int cur_col = q.front().first.second;
        string curRoute = q.front().second;
        q.pop();

        if(curRoute.length() == k){
            if(cur_row == r && cur_col == c){
                route = curRoute;
                break;
            }
            continue;
        }else if(curRoute.length() < k){
            for(int i=0;i<4;i++){   // down , left , right, up;
                int new_row = cur_row + dir_row[i];
                int new_col = cur_col + dir_col[i];
                if(new_row>=1 && new_row<= n && new_col >= 1 && new_col <= m){
                    string newRoute = curRoute;
                    if(i==0){
                        newRoute.push_back('d');
                    }else if(i==1){
                        newRoute.push_back('l');
                    }else if(i==2){
                        newRoute.push_back('r');
                    }else{
                        newRoute.push_back('u');
                    }
                    q.push({{new_row,new_col},newRoute});
                }
            }   
        }else{
            break;
        }
    }

    answer = route;
    
    return answer;
}