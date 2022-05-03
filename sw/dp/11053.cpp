#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[1000] = {0,};
int cnt[1000] = {0,};

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cnt[0]=1;
    int max = 1 ;
    for(int i=1;i<n;i++){
        int temp = 0;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]&&cnt[j]>temp){
                temp = cnt[j];
            }
        }
        cnt[i] = temp+1;
        if(cnt[i]>max){
            max = cnt[i];
        }
    }
    cout << max;
    return 0;
}
