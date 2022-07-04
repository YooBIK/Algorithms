#include <iostream>
#include <vector>
using namespace std;

int t,n;


vector<int> vec({1,2,3});
int cnt = 0;

void dfs(int sum){
    if(sum==n){
        cnt++;
        return;
    }

    if(sum>n) return;

    for(int i=0;i<vec.size();i++){
        sum += vec[i];
        dfs(sum);
        sum -= vec[i];
    }
}


int main(){
    cin >> t;
    vector<int> result;
    for(int i=0;i<t;i++){
        cin >> n;
        dfs(0);
        result.push_back(cnt);
        cnt=0;
    }
    for(int i=0;i<result.size();i++){
        cout << result[i] << "\n";
    }
    return 0;
}