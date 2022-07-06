#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    string mark = "abcdefghijklmnopqrstuvwxyz";
    cin >> str;
    int find =0;
    int arr[26];
    for(int i=0;i<26;i++){
        arr[i] = -1;
    }
    for(int i=0;i<mark.length();i++){
        for(int j=0;j<str.length();j++){
            if(mark[i]==str[j]){                
                arr[i] = j;
                find =1;
                break;
            }else{
                find =0;
            }
        }
        if(find==0){
            arr[i] == -1;
        }
    }
    for(int i=0;i<26;i++){
        cout << arr[i] << " " ;
    }
    return 0;
}