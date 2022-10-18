#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long result = -1;
int n,m;
vector<long long> trees;

int main(){
    cin >> n >> m;

    long long max_val = 0;
    for(int i=0;i<n;i++){
        long long x;
        cin >> x;
        trees.push_back(x);
        max_val = max(max_val,x);
    }

    long long start = 0;
    long long end = max_val;

    while(start<=end){
        long long mid = (end+start)/2;
        long long sum = 0;
        for(int i=0;i<trees.size();i++){
            if(trees[i]>mid){
                sum += trees[i]-mid;
            }
        }
        if(sum >= m){
            start = mid + 1;
            result = max(result,mid);
        }
        else{
            end = mid -1;
        }
    }
    cout << result;    
    return 0;
}