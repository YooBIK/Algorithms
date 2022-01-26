#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> list;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        list.push_back(x);
    }
    sort(list.begin(),list.end());

    for(int i=0;i<list.size();i++){
        cout << list[i] << "\n";
    }
    return 0;
}