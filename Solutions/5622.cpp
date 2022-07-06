#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    cin >> str;
    int time=0;
    if(str.length()>15||str.length()<2){
        return 0;
    }
    for(int i=0;i<str.length();i++){
        if(str[i]=='A'||str[i]=='B'||str[i]=='C'){
            time +=3;
        }
        if(str[i]=='D'||str[i]=='E'||str[i]=='F'){
            time +=4;
        }
        if(str[i]=='G'||str[i]=='H'||str[i]=='I'){
            time +=5;
        }
        if(str[i]=='J'||str[i]=='K'||str[i]=='L'){
            time +=6;
        }
        if(str[i]=='M'||str[i]=='N'||str[i]=='O'){
            time +=7;
        }
        if(str[i]=='P'||str[i]=='Q'||str[i]=='R'||str[i]=='S'){
            time +=8;
        }
        if(str[i]=='T'||str[i]=='U'||str[i]=='V'){
            time +=9;
        }
        if(str[i]=='W'||str[i]=='X'||str[i]=='Y'||str[i]=='Z'){
            time +=10;
        }
    }
    cout << time;
    return 0;
}