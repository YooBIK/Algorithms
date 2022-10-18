#include <iostream>

using namespace std;

int arr[1000];
int dp[1000];

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    dp[0] = 1;
    int max_num = dp[0];
    for(int i=1;i<n;i++){
        dp[i] = 1;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[j]+1,dp[i]);
            }
        }
        max_num = max(max_num,dp[i]);
    }
    cout << max_num;
    return 0;
}