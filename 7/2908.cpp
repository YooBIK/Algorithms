#include <iostream>
#include <string>
using namespace std;

int main(){
    string str1,str2,str3;
    cin >> str1 >> str2;

    for(int i=2;i>=0;i--){
        if(str1[i]<str2[i]){
            str3 = str2;
            break;
        }else if(str1[i]>str2[i]){
            str3= str1;
            break;
        }
    }
    cout << str3[2] << str3[1] << str3[0];
    return 0;
}