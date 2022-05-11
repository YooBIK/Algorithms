#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

long long n,m;


int factor(long long num, int x){
    long long cnt =0;
    // num���� �۰ų� ���� �� �߿��� 
    // x, x^2, x^3, ...�� ������ �������� ���ڵ��� �� ���� 
    for(long long i=x;i<=num; i*=x){
        cnt += num / i;
    }    
    return cnt;
}

int main(){
    cin >> n >> m;
    long long k = n-m;

    int five = factor(n,5) - factor(m,5) - factor(k,5);
    int two = factor(n,2) - factor(m,2) - factor(k,2);
   
    int result = min(five,two);
    cout << result;
    return 0;
}