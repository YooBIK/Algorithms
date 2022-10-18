#include <iostream>

using namespace std;

int scores[300];
int arr[300];

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> scores[i];
    }
    arr[0] = scores[0];
    arr[1] = scores[0] + scores[1];
    arr[2] = max(scores[2]+scores[0], scores[2]+scores[1]);
    for(int i=3;i<=n;i++){
        arr[i] = max(arr[i-3]+scores[i-1]+scores[i], arr[i-2]+scores[i]);
    }
    cout << arr[n-1];
    return 0;   
}