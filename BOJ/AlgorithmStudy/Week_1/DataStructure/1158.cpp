#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue<int> q;
vector<int> result;

int main(){
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        q.push(i);
    }

    while(!q.empty()){
        for(int j=0;j<k-1;j++){
            q.push(q.front());
            q.pop();
        }
        result.push_back(q.front());
        q.pop();
    }
    cout << "<";
    for(int i=0;i<result.size()-1;i++){
        cout  << result[i] << ", ";
    }
    cout << result[result.size()-1] << ">";
    return 0;
}