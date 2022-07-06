#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, q;
string name = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int check[26] = {0,};
int num[10001] = {0,};
char who[10001] = {0,};

int main(){
    cin >> n >> k >> q;
    for(int i=1;i<=k;i++){
        int a;
        char c;
        cin >> a >> c;
        num[i] = a;
        who[i] = c;
    }

    if(num[q]==0){
        cout << "-1";
        return 0;
    }

    for(int i=1;i<=k;i++){
        if(num[q]<=num[i]){
            check[(who[i]-'A')]=1;
        }
    }
    check[0] = 1;
    for(int i=0;i<n;i++){
        if(check[i]==0){
            cout << name[i] << " ";
        }
    }
        
    return 0;
}