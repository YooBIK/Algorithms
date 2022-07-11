#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[1000001];
vector<int> vec;
vector<pair<int,int>> result;

void prime_num(){
    arr[0] = 1;
    arr[1] = 1;
    for(int i=2;i*i<=1000000;i++){
        if(arr[i]==0){
            for(int j=i*2;j<=1000000;j+=i){
                arr[j]=1;
            }
        }
    }
}

int main(){
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    prime_num();
    while(1){
        cin >> n;
        if(n==0){
            break;
        }
        
        bool flag=false;
        for(int i=3;i*2<=n;i+=2){
            if(!arr[i] && !arr[n-i]){
                cout << n << " = " << i << " + " << n-i << "\n";
                flag = true;
                break;
            }
        }
        if(!flag) cout << "Goldbach's conjecture is wrong." << "\n";
    }
    return 0;
}
