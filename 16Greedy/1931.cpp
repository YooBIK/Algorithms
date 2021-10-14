#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//현 상황에서 시작할수 있는 회의중에서 가장 먼저 끝나는 회의를 우선으로

int main(){
    int n;
    int result=1;
    vector<pair<int,int>> arr;
    vector<pair<int,int>> temp;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a>>b;
        pair<int,int> x = make_pair(b,a);
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    int endtime = arr[0].first;
    for(int i=1;i<n;i++){
        if(arr[i].second>=endtime){
            result++;
            endtime=arr[i].first;
        }
    }
    cout << result;
    return 0;
}
