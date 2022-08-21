#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;


int n,k;
vector<pair<int,int>> jewelrys;
vector<int> bags;

bool comp(pair<int,int> a,pair<int,int> b){
    if(a.first == b.first){
        return a.second<b.second;
    }else{
        return a.first<b.first;
    }
}

int main(){
    cin >> n >> k;

    for(int i=0;i<n;i++){
        long long weight, price;
        cin >> weight >> price;
        jewelrys.push_back({weight,price});
    }
    for(int i=0;i<k;i++){
        long long x;
        cin >> x;
        bags.push_back(x);
    }
    sort(jewelrys.begin(),jewelrys.end());
    sort(bags.begin(),bags.end());
    
    priority_queue<int,vector<int>,less<int>> pq; 

    long long sum = 0;
    int index = 0;
    for(int i=0;i<bags.size();i++){
        while(index<jewelrys.size() && jewelrys[index].first <= bags[i]){
            pq.push(jewelrys[index].second); 
            index++;           
        }
        if(!pq.empty()){
            sum+= pq.top();
            pq.pop();
        }
    }
    cout << sum;    
    return 0;
}