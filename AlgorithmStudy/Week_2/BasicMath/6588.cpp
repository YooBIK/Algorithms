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
    prime_num();
    while(1){
        cin >> n;
        if(n==0){
            break;
        }

        for(int i=2;i<=n;i++){
            if(arr[i]==0 && i%2==1){
                vec.push_back(i);
            }
        }
        bool flag = false;
        for(int i=0;i<vec.size()-1;i++){
            for(int j=vec.size()-1;j>i;j--){
                if(vec[i]+vec[j] == n){
                    flag = true;
                    cout << n << " = " << vec[i] << " + " << vec[j] << "\n";  
                    break;
                }
            }
            if(flag) break;
        }
        
        if(!flag) cout << "Goldbach's conjecture is wrong." << "\n";
        vec.clear();
    }
}