#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    vector<long long> vec;
    
    cin >> n;
    long long max_val = 0;
    for(int i=0;i<n;i++){
        long long x;
        cin >> x;
        max_val = max(max_val,x);
        vec.push_back(x);
    }
    cin >> m;

    long long start = 1;
    long long end = max_val;
    long long result =0;
    while(end>=start){
        long long mid = (start+end)/2;
        long long sum = 0;
        for(int i=0;i<vec.size();i++){
            if(vec[i]>mid){
                sum += mid;
            }else{
                sum += vec[i];
            }
        }
        if(sum > m){
            end = mid-1;
        }else{
            start = mid+1;
            result = max(result,mid);
        }
    }
    cout << result;
    return 0;





}                   