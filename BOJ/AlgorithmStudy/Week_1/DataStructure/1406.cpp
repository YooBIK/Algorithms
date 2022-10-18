#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

stack<char> left_side;
stack<char> right_side;

int main(){
    int n;
    string str;
    getline(cin,str);

    for(int i=0;i<str.length();i++){
        left_side.push(str[i]);
    }


    cin >> n;
    cin.ignore();

    for(int i=0;i<n;i++){
        string temp;
        getline(cin,temp);
        if(temp == "L"){
            if(left_side.empty()){
                continue;
            }else{
                char ch = left_side.top();
                left_side.pop();
                right_side.push(ch);
            }
        }else if(temp == "D"){
            if(right_side.empty()){
                continue;
            }else{
                char ch = right_side.top();
                right_side.pop();
                left_side.push(ch);    
            }
        }else if(temp == "B"){
            if(left_side.empty()){
                continue;
            }else{
                left_side.pop();
            }
        }else{
            char ch;
            stringstream ss;
            ss.str(temp);
            ss>> ch >> ch;
            left_side.push(ch);
        }
    }
    while(!left_side.empty()){
        char ch = left_side.top();
        right_side.push(ch);
        left_side.pop();
    }
    string result = "";
    while(!right_side.empty()){
        result.push_back(right_side.top());
        right_side.pop();
    }
    cout << result;
    return 0;
}