#include <iostream>

using namespace std;

int arr[500][500];
int check[500][500];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin >> arr[i][j];
        }
    }

    check[0][0] = arr[0][0];
    for(int i=1;i<n;i++){
        check[i][0] = check[i-1][0] + arr[i][0];
        for(int j=1;j<i;j++){
            check[i][j] = max(check[i-1][j-1],check[i-1][j])+arr[i][j];
        }
        check[i][i] = check[i-1][i-1] + arr[i][i];
    }

    int result =0;
    for(int i=0;i<n;i++){
        result = max(result, check[n-1][i]);
    }
    cout << result;

}