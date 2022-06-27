#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> result;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        result.push_back(x);
    }
    sort(result.begin(),result.end());
    for(int i=0;i<result.size();i++){
        cout << result[i] << "\n";
    }

    return 0;
}