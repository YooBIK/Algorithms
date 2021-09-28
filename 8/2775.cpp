#include <iostream>
using namespace std;

int main(){
    int ntest;
    cin >> ntest;
    while(ntest>0){
        int k,n;
        cin >> k;
        cin >> n;
        int arr[15][15]={0,};
        for(int i=1;i<=n;i++){
            arr[0][i]=i;
        }
        for(int i=1;i<=k;i++){
            int sum = 0;
            for(int j=1;j<=n;j++){
                sum += arr[i-1][j];
                arr[i][j]=sum;
            }
        }
        cout << arr[k][n] <<"\n";
        ntest--;   
    }
    return 0;
}