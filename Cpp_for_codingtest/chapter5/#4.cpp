#include <iostream>
using namespace std;

void recursive_fuc(int i){
    if(i==100){
        return;
    }else{
        cout << i  <<"��° ��� �Լ���" <<i+1<<"�� ° �Լ� ȣ��"<<"\n";
        recursive_fuc(i+1);
    }
}

int main(){
    recursive_fuc(0);
    return 0;
}