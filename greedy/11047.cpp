#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n,k;
    vector<int> vec;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }
    int count = 0;
    for(int i=n-1;i>=0;i--){
        if(k>=vec[i]){
            count += k/vec[i];
            k=k%vec[i];
        }
        // if(k==0){
        //     break;
        // }
    }
    cout << count ;
    return 0;
}