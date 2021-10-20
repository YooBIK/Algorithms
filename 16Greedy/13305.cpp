#include <iostream>
#include <vector>
using namespace std;

int main(){
    long n;
    cin >> n;
    if(n<2||n>1000) return 0;
    vector<long> dist;
    vector<long> cost;
    long totaldist =0;
    for(int i=0;i<n-1;i++){
        long x;
        cin >> x;
        totaldist += x;
        dist.push_back(x);
    }
    if(totaldist>10000) return 0;

    for(int i=0;i<n;i++){
        long x;
        cin >>x;
        if(x>10000) return 0;
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