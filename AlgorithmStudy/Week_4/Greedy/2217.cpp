#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> ropes;

bool comp(int a, int b){
    return a>b;
}


int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        ropes.push_back(x);
    }
    sort(ropes.begin(),ropes.end(),comp);
    int num = 0;
    int result = 0;
    for(int i=0;i<ropes.size();i++){
        if(result <= ropes[i] * (num + 1)){
            result = ropes[i] * (num+1);
            num++;
        }
    }
    cout << result;

    return 0;
}