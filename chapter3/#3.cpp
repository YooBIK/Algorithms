#include <iostream>
using namespace std;

int main(){
    int arr[101][101] = {0,};
    int rmin[101]={0,};
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        int min = arr[i][1];
        for(int j=2;j<=m;j++){
            if(min>arr[i][j]){
                min = arr[i][j];
            }
        }

        rmin[i]=min;
    }
    int result = 0;

    for(int i=1;i<=n;i++){
        if(rmin[i]>result){
            result = rmin[i];
        }
    }
    cout << result;
    return 0;
}
