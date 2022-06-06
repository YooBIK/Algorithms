#include <iostream>
#include <string>
using namespace std;

int main(){
    int ndata;
    cin >> ndata;
    int result=0;
    for(int i=0;i<ndata;i++){
        string str;
        cin >> str;
        int check =1;
        for(int j=0;j<str.length();j++){
            for(int k=0;k<j;k++){
                if(str[j]==str[k]&&str[j]!=str[j-1]){
                    check==0;
                    break;
                }
            }
        } 
        if(check==1){
            result++;
        }        
    }
    cout << result;
    return 0;
}