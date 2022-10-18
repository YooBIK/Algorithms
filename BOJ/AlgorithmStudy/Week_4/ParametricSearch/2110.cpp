#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> vec;

int main(){
    int n,c;
    cin >> n >> c;
    for(int i=0;i<n;i++){
        long long x;
        cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(),vec.end());

    long long result =0;
    long long start = 1;
    long long end = (1<<31)-1;
    while(end>=start){
        long long mid = (start+end)/2;
        long long cur = vec[0];
        long long cnt = 1;
        for(int i=1;i<vec.size();i++){
            if(vec[i]-cur>=mid){
                cur = vec[i];
                cnt++;
            }
        }
        if(cnt < c){
            end = mid-1;
        }else {
            result = max(result,mid);
            start = mid+1;
        }
    }
    cout << result;
    return 0;




}