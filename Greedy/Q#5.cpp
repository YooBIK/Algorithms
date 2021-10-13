#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin >> n>> m;
    vector<int> vec;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }
    int count=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(vec[i]!=vec[j]){
                count++;
            }
        }
    }
    cout << count;
    return 0;
}