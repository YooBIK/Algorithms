#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    string str;
    cin >> n >> str;
    int sum =0;
    while(!str.empty()){
        sum += (int)str.back()-'0';
        str.pop_back();
    }
    cout << sum;
    return 0;
}