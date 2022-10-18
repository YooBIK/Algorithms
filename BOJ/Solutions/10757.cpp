#include <iostream>
#include <string>
using namespace std;

int main(){
    string str1,str2,str3;
    int carry=0;
    cin >> str1 >> str2;
    while(str1.length()>0||str2.length()>0){
        int n1=0;
        if(!str1.empty()){
            n1 = str1.back() -'0';
            str1.pop_back();
        }
        int n2=0;
        if(!str2.empty()){
            n2 = str2.back() - '0';
            str2.pop_back();
        }
        int sum = n1+n2+carry;
        carry = sum/10;
        sum = sum%10;
        char ch = sum + '0';
        str3.push_back(ch);
    }
    if(carry){
        str3.push_back('1');
    }
    for(int i=str3.length()-1;i>=0;i--){
        cout<<str3[i];
    }
    return 0;  
}