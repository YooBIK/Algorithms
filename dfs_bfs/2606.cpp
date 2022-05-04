#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int map[101][101] = {0,};
int visited[101]= {0,};

int n,m;
int cnt =0;


void bfs(int a){
    queue<int> q;
    q.push(a);
    visited[a]=1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(map[x][i] == 1 && visited[i]==0){
                q.push(i);
                visited[i]=1;
                cnt ++ ;
            }
        }
    }
}

int main(){

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        map[a][b]=1;
        map[b][a]=1;
    }
    bfs(1);
    cout << cnt;
    return 0;

}