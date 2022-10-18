#include <iostream>

using namespace std;

int main(){
    long long a,b,v;
    cin >> a >> b >> v;
    long long distPerDay = a-b;
    long long start = 1;
    long long end = (1<<31)-1;
    long long result = (1<<31)-1;
    while(end>=start){
        long long mid = (start+end) / 2;
        if( (a*mid - b*(mid-1)) >= v){
            end = mid - 1;
            result = min(result,mid);
        }else{
            start = mid + 1;
        }
    }
    cout << result;
}