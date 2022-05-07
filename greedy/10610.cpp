#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;
//30의 배수가 되려면 마지막 자리 =0, 모든 자리 수의 합이 3의 배수

bool comp(int a, int b){
    return a>b;
}

int main(){
    string str;
    int flag=0;
    cin >> str;
    sort(str.begin(),str.end(),comp);
    int sum =0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='0'){
            flag =1;
        }

        sum += str[i]-'0';
    }

    if(flag==1 && sum%3==0){
        cout << str;
    }else{
        cout << -1;
    }

    return 0;

    
}