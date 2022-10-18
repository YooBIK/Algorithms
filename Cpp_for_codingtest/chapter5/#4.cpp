#include <iostream>
using namespace std;

void recursive_fuc(int i){
    if(i==100){
        return;
    }else{
        cout << i  <<"번째 재귀 함수가" <<i+1<<"번 째 함수 호출"<<"\n";
        recursive_fuc(i+1);
    }
}

int main(){
    recursive_fuc(0);
    return 0;
}