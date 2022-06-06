#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int res=n;
    int mod=0;
    vector<int> vec;
    while(res>0){
        mod = res%10;
        vec.push_back(mod);
        res=res/10;
    }
    sort(vec.begin(),vec.end());
    for(int i = vec.size()-1;i>=0;i--){
        cout << vec[i];
    }
    return 0;
}