#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> vec,result;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }
    int target = 1;
    sort(vec.begin(),vec.end());
    for(int i=0;i<n;i++){
        if(target<vec[i]){
            break;
        }
        target+=vec[i];        
    }
    cout << target;
    return 0;

}