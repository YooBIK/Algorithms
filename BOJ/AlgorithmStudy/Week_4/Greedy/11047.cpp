#include <iostream>
#include <vector>
using namespace std;

int n,k;
vector<int> coins;


int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        coins.push_back(x);
    }
    int result =0;
    while(k){
        for(int i=coins.size()-1;i>=0;i--){
            if(coins[i]<=k){
                result += k/coins[i];
                k = k%coins[i];
                break;
            }
        }
    }
    cout << result;
    return 0;
}