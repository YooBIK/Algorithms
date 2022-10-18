#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[50][50];
vector<pair<int,int>> chicken;
vector<pair<int,int>> house;




int main(){
    int n,m;
    cin >> n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            if(arr[i][j]==1){
                house.push_back({i,j});
            }
            else if(arr[i][j]==2){
                chicken.push_back({i,j});
            }
        }
    }
    int c_count=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==2){
                chicken.push_back(make_pair(i,j));
                c_count++;
            }
            if(arr[i][j]==1){
                house.push_back(make_pair(i,j));
            }
        }
    }
    int diff = c_count-m;
    vector<pair<int,int>> dist_sum;
    for(int i=0;i<chicken.size();i++){
        for(int j=0;j<house.size();j++){
            
        }
    }


}