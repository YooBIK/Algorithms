#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<=n/5;i++){
        for(int j=0;j<=n/3;j++){
            if(5*i+3*j==n){
                v.push_back(i+j);
            }
        }
    }
    if(v.empty()){
        cout << "-1";
    }else{
        int min = v.back();
        v.pop_back();
        while(!v.empty()){
            if(min>v.back()){
                min=v.back();
            }
            v.pop_back();
        }
        cout << min;
    }
    return 0;
}