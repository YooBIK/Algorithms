#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int arr[100001]={0,};
int visit[100001];
vector<int> temp;


int t,n,m;
vector<int> result;

void dfs(int cur){

    if(visit[cur]==2){
        int index;
        for(int i=0;i<temp.size();i++){
            if(temp[i]==cur){
                index = i;
            }
        }
        for(int i=0;i<temp.size();i++){
            if(i<index){
                visit[temp[i]] = -1;
            }else{
                visit[temp[i]] = 1;
            }
        }
        temp.clear();
        return;
    }

    if(visit[cur] == -1 || visit[cur]==1){
        for(int i=0;i<temp.size();i++){
            visit[temp[i]]=-1;
        }
        temp.clear();
        return;
    }


    visit[cur] = 2;
    temp.push_back(cur);
    dfs(arr[cur]);
}

void init(){
    for(int i=1;i<=n;i++){
        arr[i] = 0;
        visit[i] = 0;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        m = n;
        for(int j=1;j<=n;j++){
            cin >> arr[j];
        }
        for(int j=1;j<=n;j++){
            dfs(j);
        }
        int cnt =0;
        for(int j=1;j<=n;j++){
            if(visit[j]==-1) cnt++;
        }
        cout << cnt << "\n";
        init();
    }

    return 0;
}