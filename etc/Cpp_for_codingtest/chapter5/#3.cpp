#include<iostream>
using namespace std;

void recursive_fuc(){
    cout << "��� �Լ� ȣ��";
    recursive_fuc();
}

int main(){
    recursive_fuc();
    return 0;
}