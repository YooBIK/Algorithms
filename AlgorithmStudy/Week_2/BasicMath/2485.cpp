#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> vec;

int gcd(int a, int b){
    int c = a%b;
    while(b){
        int c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }
    vector<int> dist;
    for(int i=0;i<vec.size()-2;i++){
        int x = vec[i+1]-vec[i];
        dist.push_back(x);
    }
    sort(dist.begin(),dist.end());
    dist.erase(unique(dist.begin(),dist.end()),dist.end());

    int num = gcd(dist[0],dist[1]);
    for(int i=2;i<dist.size()-1;i++){
        num = gcd(num,dist[i]);        
    }
    cout << ((vec[vec.size()-1] - vec[0]) / num) - (vec.size()-1) ;


    return 0;
}