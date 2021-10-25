#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    string str;
    int result=0;
    int count=1;
    cin >> str;
    for(int i=0;i<str.length()-1;i++){
        if(str[i]!=str[i+1]){
            count++;
        }
    }
    result=count/2;
    cout << result;
    return 0;

}