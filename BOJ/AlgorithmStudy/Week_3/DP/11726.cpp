#include <iostream>

using namespace std;

int arr[1001] = {0,};


int main(){
    arr[1] = 1;
    arr[2] = 2;

    for(int i=3;i<=1000;i++){
        arr[i] = (arr[i-1] + arr[i-2]) % 10007;
    }

    int n;
    cin >> n;
    cout << arr[n];
    return 0;
}