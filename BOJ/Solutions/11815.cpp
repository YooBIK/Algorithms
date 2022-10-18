#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int cnt_num(long long num){
    if(num==(long long)sqrt(num)*(long long)sqrt(num)){ // 제곱근이 정수
        return 1;
    }else{          // 제곱근이 정수X
        return 0;
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        long long x;
        cin >> x;
        cout << cnt_num(x) << " ";
    }
}