#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long k,n;
vector<long long> lan;
int main(){
    cin >> k >> n;
    long long max_val = 0;
    for(int i=0;i<k;i++){
        long long x;
        cin >> x;
        max_val = max(max_val,x);
        lan.push_back(x);
    }
    long long result = 0;
    long long start = 1;
    int end = (1<<31)-1;
    while(end>=start){
        long long mid = (start+end)/2;
        long long cnt = 0;
        for(int i=0;i<lan.size();i++){
            cnt += lan[i]/mid;
        }
        if(cnt>=n){
            result = max(mid,result);
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    cout << result;
    return 0;
}