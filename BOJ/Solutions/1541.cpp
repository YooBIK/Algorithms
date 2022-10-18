#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
int main(){
    string str;
    cin >> str;
    int index =0;
    vector<int> vec;
    vector<char> oper;
    for(int i=0;i<str.length();i++){
        if(str[i] == '+' || str[i]=='-'){
            oper.push_back(str[i]);
            vec.push_back(stoi(str.substr(index, i-index)));
            index = i+1;
        }
    }
    vec.push_back(stoi(str.substr(index)));
    int result = 0;
    int flag =0;
    int wh ;
    for(int i=0;i<oper.size();i++){
        if(oper[i]=='-'){
            flag = 1;
            wh=i+1;
            break;
        }
    }
    if(flag==1){
        for(int i=0;i<wh;i++){
            result += vec[i];
        }
        for(int i=wh;i<vec.size();i++){
            result -= vec[i];
        }
    }else{
        for(int i=0;i<vec.size();i++){
            result += vec[i];
        }
    }
    
    cout << result;
    return 0;
}