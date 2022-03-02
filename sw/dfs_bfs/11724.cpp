#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;

int map[1001][1001] = {0,};
int visit[1001] = {0,};

queue<int> q;

void bfs(int x){
    q.push(x);
    visit[x] =1;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(map[a][i]==1 && visit[i]==0){
                q.push(i);
                visit[i]=1;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    int count =0;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
    for(int i=1;i<=n;i++){
        if(visit[i]==0){
            bfs(i);
            count++;
        }
    }
    cout << count;
    return 0;
}
