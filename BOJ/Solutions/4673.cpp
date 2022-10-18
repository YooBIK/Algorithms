#include <iostream>
using namespace std;

int self_number(int n){
    int sum =n;
    while(n>0){
        sum += n%10;
        n /= 10;
    }
    if(sum>10000){
        return 0;
    }else{
        return sum;
    }

}

int main(){
    int arr[10001]={0,};
    for(int i=1;i<10001;i++){
        arr[self_number(i)] = 1;
    }
    for(int i =1; i<10001;i++){
        if(arr[i]==0){
            cout << i << "\n" ;
        }
    }
    return 0;
}