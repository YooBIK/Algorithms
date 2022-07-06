#include<iostream>
#include<vector>
using namespace std;

int x,y;
long long a0,a1;
long long n;


int main(){    
    cin >> x >> y >> a0 >> a1 >> n;  
    int num;  
    if(n==0){
        num = a0;
    }else if(n==1){
        num = a1;
    }else{
        for(long long i=2;i<=n;i++){
        num = (x*a1 + y*a0)%100;
        a0=a1;
        a1=num;
        }
    }
    if(num<10){
        cout << 0 << num;
    }else{
        cout << num;
    }
    return 0;
}