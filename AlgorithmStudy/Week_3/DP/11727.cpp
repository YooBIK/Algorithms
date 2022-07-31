#include <iostream>

using namespace std;

int arr[1001] = {0,};

int main(){
    arr[1] = 1;
    arr[2] = 3;
    arr[3] = 5;
    for(int i=4;i<=1000;i++){
        arr[i] = (arr[i-1] + 2*arr[i-2])%10007;
    }
    int n;
    cin >> n;
    cout << arr[n];
    return 0;
}