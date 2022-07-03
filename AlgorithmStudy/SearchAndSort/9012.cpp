#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<string> result;

int main(){
    cin >> n;

    for(int i=0;i<n;i++){
        string str;
        stack<char> checker;
        cin >> str;
        int flag = 0;
        for(int j=0;j<str.length();j++){
            if(str[j]=='('){
                checker.push(str[j]);
            }else{
                if(checker.empty()){
                    result.push_back("NO");
                    flag =1;
                    break;
                }else{
                    checker.pop();
                }
            }
        }
        if(flag==0){
            if(!checker.empty()){
                result.push_back("NO");
            }else{
                result.push_back("YES");
            }
        }
    }

    for(int i=0;i<result.size();i++){
        cout << result[i] << "\n";
    }

    return 0;
}