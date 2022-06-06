#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    vector<int> vec;
    cin >> n;
    for(int i=0;i<=n/5;i++){
        for(int j=0;j<=n/3;j++){
            if(i*5+j*3==n){
                vec.push_back(i+j);
            }
        }
    }
    if(vec.empty()){
        cout << -1 ;

    }else{
        sort(vec.begin(),vec.end());
        cout << vec[0];

    }
    return 0;
}