#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> ex;
    ex.push(5);
    ex.push(2);
    ex.push(3);
    ex.push(7);
    ex.pop();
    ex.push(1);
    ex.push(4);
    ex.pop();
    while(!ex.empty()){
        cout << ex.top();
        ex.pop();
    }
    
    return 0;

}