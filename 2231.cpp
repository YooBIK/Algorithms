#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> vec;
    for(int i=1;i<n;i++){
        int x = i;
        int sum = x;
        while(x!=0){
            sum += x%10;
            x = x/10;
        }
        if(sum==n){
            vec.push_back(i);
        }
    }
    if(vec.empty()){
        cout << 0;
    }else{
        cout <<vec[0];
    }
    return 0;
}