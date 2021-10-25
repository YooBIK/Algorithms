#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n,m,k;
    cin >>n>>m>> k;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n); // 오름차순으로 정렬
    int max = arr[n-1];
    int sec_max = arr[n-2];
    int count=0;
    int result=0;
    for(int i=0;i<m;i++){
        if(count<k){
            result += max;
            count++;
        }else{
            result += sec_max;
            count=0;
        }
    }
    cout << result;
    return 0;

}