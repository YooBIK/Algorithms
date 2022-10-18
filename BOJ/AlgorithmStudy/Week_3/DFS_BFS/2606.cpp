#include <iostream>
#include <queue>
using namespace std;

int arr[101][101];
int visit[101];

int n,m;

void bfs(int start){
    queue<int> q;
    q.push(start);
    visit[start] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(visit[i]==0 && arr[x][i]==1){
                q.push(i);
                visit[i] = 1;
            }
        }
    }
}


int main(){
    cin >> n;
    cin >> m;
    for(int i=0;i<m;i++){
        int s,e;
        cin >> s >> e;
        arr[s][e] = 1;
        arr[e][s] = 1;
    }
    bfs(1);
    int cnt = -1;
    for(int i=1;i<=n;i++){
        if(visit[i]){
            cnt++;
        }  
    }
    cout << cnt;
    return 0;
}