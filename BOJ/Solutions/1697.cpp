#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int visit[100001] = {0,};
queue<pair<int,int>> q;
int cnt = 0 ;

int bfs(int n,int k){
    visit[n] = 1;
    q.push({n,0});
    while(!q.empty()){
        int location = q.front().first;
        int time = q.front().second;
        q.pop();

        if(location == k) return time;
        if(location+1 < 100001 &&visit[location+1]==0) {
            q.push({location+1,time+1});
            visit[location+1]=1;
        }
        if(location-1 >=0 && visit[location-1]==0) {
            q.push({location-1,time+1});
            visit[location-1]=1;
        }
        if(location*2 < 100001 && visit[location*2]==0) {
            q.push({location*2,time+1});
            visit[location*2]=1;
        }
     
    }
}

int main(){
    int n,k;
    cin >> n >> k;
    cout << bfs(n,k);
    return 0;

}