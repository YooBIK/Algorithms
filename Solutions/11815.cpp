#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int cnt_num(long long num){
    if(num==(long long)sqrt(num)*(long long)sqrt(num)){ // �������� ����
        return 1;
    }else{          // �������� ����X
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