#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>

int arr[3] = {300, 60, 10};

using namespace std;

int main(){
    int T;
    cin >> T;
    int result[3]={0,0,0};
    for(int i=0;i<3;i++){
        if(T>=arr[i]){
            result[i]=T/arr[i];
            T=T%arr[i];
        }
    }
    if(T!=0){
        cout << -1;
    }else{
        for(int i=0;i<3;i++){
            cout << result[i] << " ";
        }
    }
    return 0;
}