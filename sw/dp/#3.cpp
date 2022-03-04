#include <iostream>
#include <algorithm>

using namespace std;

int arr[100] = {0,};
int ans[100]={0,};
int n;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    ans[0]= arr[0];
    ans[1]= max(arr[0],arr[1]);
    for(int i=2;i<n;i++){
        ans[i] = max(ans[i-1],ans[i-2]+arr[i]);
    }

    cout << ans[n-1];
    return 0;
}