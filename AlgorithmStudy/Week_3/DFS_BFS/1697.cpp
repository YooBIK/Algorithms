#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int visit[100001];

int n,m;
vector<int> result;

int bfs(int x,int num){
    visit[x] = true;
    queue<pair<int,int>> q;
    q.push({x,num});

    while(!q.empty()){
        pair<int,int> next = q.front();
        q.pop();
        int loc = next.first;
        int time = next.second;
        if(loc==m){
            return time;
        }
        if(loc+1<=100000 && !visit[loc+1]){
            q.push({loc+1,time+1});
            visit[loc+1] = true;
        }

        if(loc-1>=0 && !visit[loc-1]){
            q.push({loc-1,time+1});
            visit[loc-1] = true;
        }

        if(loc*2 <=100000 && !visit[loc*2]){
            q.push({loc*2,time+1});
            visit[loc*2] = true;
        }
    }
}

int main(){
    cin >> n >> m;
    cout << bfs(n,0);
    return 0;
}