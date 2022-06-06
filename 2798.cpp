#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    vector<int> vec;
    cin >> n>>m;
    int diff = m;
    int result=0;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                int sum=0;
                sum = vec[i]+vec[j]+vec[k];
                if(sum<= m && m-sum<diff){
                    diff = m-sum;
                    result = sum;
                }
            }
        }
    }
    cout << result;
    return 0;
}