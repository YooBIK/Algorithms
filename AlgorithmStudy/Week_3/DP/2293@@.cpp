#include <iostream>
#include <vector>
using namespace std;

vector<int> coin;
int dp[10001];

int main(){
    int n,k;
    cin >> n >> k;

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        coin.push_back(x);
    }

    for(int i=0;i<coin.size();i++){
        dp[coin[i]]++;
    }
    


}