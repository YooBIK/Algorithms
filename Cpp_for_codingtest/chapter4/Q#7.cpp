#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    cin >>str;
    int front=0;
    int back=0;
    int mid = str.length()/2;
    for(int i=0;i<mid;i++){
        front += str[i]-'0';
    }
    for(int i=mid;i<str.length();i++){
        back += str[i]-'0';
    }
    if(front == back){
        cout << "LUCKY";
    }else{
        cout << "READY";
    }
    return 0;

}