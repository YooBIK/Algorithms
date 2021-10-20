#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    vector<int> vec;
    string inputstr;
    string number, oper;  
    int index=0;
    int flag=0;
    int result=0;
    cin >> inputstr;
    for(int i=0;i<inputstr.length();i++){
        if(inputstr[i]!='+'&&inputstr[i]!='-'){ // 연산자가 아니면 number에 푸쉬 
            number += inputstr[i];
        }else{
            vec.push_back(stoi(number)); //연산자면 지금까지 들어온 number를 vec에 저장
            number.clear();
            oper += inputstr[i];
        }
    }
    vec.push_back(stoi(number));
    for(int i=0;i<oper.length();i++){
        if(oper[i]=='-'){
            flag=1;
            index = i;
            break;
        }
    }
    if(flag==1){
        for(int i=0;i<=index;i++){
            result += vec[i];
        }
        for(int i=index+1;i<vec.size();i++){
            result-=vec[i];
        }
    }else{
        for(int i=0;i<vec.size();i++){
            result += vec[i];
        }
    }
    cout <<result;
    return 0;
}