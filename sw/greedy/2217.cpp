#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    vector<int> vec;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(),vec.end());
    int max=0;
    for(int i=0;i<vec.size();i++){
        if(vec[i]*(n-i)>=max){
            max = vec[i]*(n-i);
        }
    }
    cout << max;
    return 0;

}