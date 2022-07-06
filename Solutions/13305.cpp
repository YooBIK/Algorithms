#include <iostream>
#include <vector>
using namespace std;

int main(){
    long n;
    cin >> n;
    vector<long> dist;
    vector<long> cost;
    for(int i=0;i<n-1;i++){
        long x;
        cin >> x;
        dist.push_back(x);
    }
    for(int i=0;i<n;i++){
        long x;
        cin >>x;
        cost.push_back(x);
    }
    long totalcost =0;
    long mincost = cost[0];
    for(int i=1;i<n-1;i++){
        if(cost[i]>mincost){
            cost[i]=mincost;
        }else{
            mincost=cost[i];
        }
    }
    for(int i=0;i<n-1;i++){
        totalcost += dist[i]*cost[i];
    }
    cout <<totalcost;
    return 0;
}