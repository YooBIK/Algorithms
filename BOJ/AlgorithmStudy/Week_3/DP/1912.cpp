#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000] = {0,};
int dp[100000] ;

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    dp[0] = arr[0];
    int result = dp[0];
    for(int i=1;i<n;i++){
        dp[i] = max(dp[i-1]+arr[i],arr[i]);
        if(dp[i]>result) result = dp[i]; 
    }
    cout << result;
    return 0;
}