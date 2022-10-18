#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int arr[1001][1001] = {0,};

int check_dfs[1001]={0,};
int check_bfs[1001]={0,};

void dfs(int v){
    check_dfs[v]=1;
    cout << v << " ";
    for(int i=1;i<=1000;i++){
        if(arr[v][i]==1&&check_dfs[i]==0){
            dfs(i);

        }
    }
    
}

void bfs(int v){
    queue<int> q;
    q.push(v);
    check_bfs[v]=1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout << x << " ";
        for(int i=1;i<=1000;i++){
            if(arr[x][i]==1 && check_bfs[i]==0){
                q.push(i);
                check_bfs[i]=1;
            }
        }
    }

}

int main(){
    int n,m,v;
    cin >> n >> m >> v;
    for(int i=0;i<m;i++){
        int row,col;
        cin >> row >> col;
        arr[row][col]=1;
        arr[col][row]=1;
    }
    dfs(v);
    cout << "\n";
    bfs(v);
    return 0;
}