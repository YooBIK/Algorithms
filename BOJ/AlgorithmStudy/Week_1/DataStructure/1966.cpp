#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

vector<int> result;

int main(){

    int t,n,m;
    cin >> t;
    for(int i=0;i<t;i++){
        vector<pair<int,int>> num_list;
        cin >> n >> m;
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            num_list.push_back({j,x});
        }
        int cnt = 0;
        while(1){
            int pop_flag = 0;
            for(int i=1;i<num_list.size();i++){
                if(num_list[0].second< num_list[i].second){
                    pop_flag=1;
                    pair<int,int> temp = num_list[0];
                    num_list.erase(num_list.begin());
                    num_list.push_back(temp);
                    break; 
                }
            }
            if(!pop_flag){
                if(num_list[0].first == m){
                    num_list.erase(num_list.begin());
                    cnt++;
                    break;
                }else{
                    num_list.erase(num_list.begin());
                    cnt++;
                }
            }
        }
        result.push_back(cnt);
    }
    for(int i=0;i<result.size();i++){
        cout << result[i] << "\n";
    }

    return 0;
}