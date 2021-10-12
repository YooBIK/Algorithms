#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    string str;
    cin >> str;
    int arr[20]={0,};
    for(int i=0;i<str.length();i++){
        arr[i]=str[i]-'0';
    }
    int result= arr[0];
    for(int i=1;i<str.length();i++){
        if(arr[i]==1||arr[i]==0||result<=1){
            result+=arr[i];
        }else{
            result *=arr[i];
        }
    }
    cout << result;
    return 0;
    
}