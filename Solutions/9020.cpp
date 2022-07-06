#include <iostream>
using namespace std;

int main(){
    bool arr[10001];
    for(int i=0;i<10001;i++){
        arr[i]=true;
    }
    arr[0]=false;
    arr[1]=false;
    for(int i=0;i<=10000;i++){
        if(arr[i]){
            for(int j=2*i;j<=10000;j+=i){
                arr[j]=false;
            }
        }
    }
    int ntest;
    cin >> ntest;
    while(ntest>0){
        int n;
        cin >> n;
        int mid = n/2;
        if(arr[mid]){
            cout << mid << " " << mid << "\n";
        }else{
            int minpart=mid-1;        
            while(1){
                if(arr[minpart]&&arr[n-minpart]){
                    cout << minpart << " " << n-minpart << "\n";
                    break;
                }else{
                    minpart--;
                }
            }
        }
        ntest--;
    }
    return 0;
}