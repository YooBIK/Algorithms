#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 99999;
int n;
vector<int> vec;

int main(){

    cin >> n;
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(1);

    if(n>4){
        for(int i=4;i<=n;i++){
            int a=INF;
            int b=INF;
            int c=INF;
            if(i%3==0){
                a = vec[i/3]+1;
            }
            if(i%2==0){
                b = vec[i/2]+1;
            }
            c = vec[i-1]+1;
            int min_val = min({a,b,c});
            vec.push_back(min_val);
        }
    }
    cout << vec[n];

    return 0;
}