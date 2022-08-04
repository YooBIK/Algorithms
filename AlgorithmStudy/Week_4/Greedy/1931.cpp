#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int,int>> meeting;

bool comp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }

    return a.second < b.second;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int startTime,endTime;
        cin >> startTime >> endTime;
        meeting.push_back({startTime,endTime});
    }
    sort(meeting.begin(),meeting.end(),comp); 
    int curEnd = 0;
    int result =0;
    for(int i=0;i<meeting.size();i++){
        if(meeting[i].first>=curEnd){
            result ++;
            curEnd = meeting[i].second;
        }
    }
    cout << result;
    return 0;

}