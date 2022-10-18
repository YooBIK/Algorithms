#include<iostream>
using namespace std;

void recursive_fuc(){
    cout << "재귀 함수 호출";
    recursive_fuc();
}

int main(){
    recursive_fuc();
    return 0;
}