#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n;
int arr[4000001];
int cnt = 0;
vector<int> p_num_vec;

void prime_num(){
    arr[0] = 1;
    arr[1] = 1;
    for(int i=2;i*i<=n;i++){
        if(arr[i]==0){
            for(int j=i*2;j<=n;j+=i){
                arr[j]=1;
            }
        }
    }
    for(int i=0;i<=n;i++){
        if(arr[i]==0) p_num_vec.push_back(i);
    }
}

void sol(){
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n-i+1;j++){
            int sum = 0;
            for(int k=0;k<i;k++){
                sum += p_num_vec[k];
            }
            if(sum == n) cnt ++;
        }
    }
}





int main(){
    cin >> n;
    prime_num();
    sol();
    cout << cnt;
}