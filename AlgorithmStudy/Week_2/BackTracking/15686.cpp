#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n,m,max_num;
int map[51][51];
bool visit[51][51];

int result = 99999999;

vector<pair<int,int>> vec;

int carc_chicken_dist(){
    int city_chicken_dist = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(map[i][j]==1){
                int chicken_dist = 9999999;
                for(int a=0;a<vec.size();a++){
                    chicken_dist = min(chicken_dist,abs(vec[a].first-i)+abs(vec[a].second-j));
                }
                city_chicken_dist += chicken_dist;
            }
        }   
    }
    return city_chicken_dist;
}


void dfs(int row,int col,int num){
    if(num == max_num){
        result = min(result,carc_chicken_dist());
        return ;
    }

    for(int i=row;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(!visit[i][j] && map[i][j] == 2){
                visit[i][j] = true;
                vec.push_back({i,j});
                dfs(i,j,num+1);
                visit[i][j] = false;
                vec.pop_back();
            }
        }
    }
}

void init(){
    for(int i=0;i<51;i++){
        for(int j=0;j<51;j++){
            visit[i][j]=false;
        }
    }
    vec.clear();
}



int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> map[i][j];
        }
    }

    for(int i=1;i<=m;i++){
        max_num=i;
        dfs(1,1,0);
        init();
    }
    cout << result;
}