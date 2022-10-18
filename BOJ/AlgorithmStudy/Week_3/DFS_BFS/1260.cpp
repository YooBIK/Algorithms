#include <iostream>
#include <queue>
using namespace std;

int n,m,start_node;
int arr[1001][1001];
bool visit[1001]; 
vector<int> dfsResult;


void dfs(int index){
    visit[index]= true;
    cout << index << " ";

    for(int i=1;i<=n;i++){
        if(arr[index][i]==1 && !visit[i]){
            dfs(i);
        }
    }
}

void bfs(int index){
    queue<int> q;
    q.push(index);
    visit[index]= true;
    while(!q.empty()){
        int next = q.front();
        q.pop();
        cout << next << " ";
        for(int i=1;i<=n;i++){
            if(arr[next][i]==1 && !visit[i]){
                q.push(i);
                visit[i]=true;
            }
        }
    }
}

void init(){
    for(int i=0;i<1001;i++){
        visit[i] = false;
    }
}


int main(){
    cin >> n >> m >> start_node;
    for(int i=0;i<m;i++){
        int s,e;
        cin >> s >> e;
        arr[s][e] = 1;
        arr[e][s] = 1;
    }

    visit[start_node] = true;
    dfsResult.push_back(start_node);
    dfs(start_node);
    cout << "\n";
    init();
    bfs(start_node);
    return 0;

}