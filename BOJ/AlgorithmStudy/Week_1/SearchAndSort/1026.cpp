#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> a;
vector<int> b;

bool comp(int a,int b){
    return a>b;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin(),a.end(),comp);
    sort(b.begin(),b.end());
    int result =0;
    for(int i=0;i<n;i++){
        result += a[i]*b[i];
    }
    cout << result;
    return 0;
}