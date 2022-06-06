#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[301] = {0,};
int value[301] = {0,};



int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    value[1] = arr[1];
    value[2] = arr[2] + arr[1];

    for(int i=3;i<=n;i++){
        value[i] = max(value[i-2] + arr[i],value[i-3]+arr[i-1]+arr[i]);
    }
    cout << value[n];
    return 0;
}