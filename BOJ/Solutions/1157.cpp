#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    cin >> str;
    int arr[52] = {0,};
    string mark = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" ;

    for(int i=0;i<mark.length();i++){
        for(int j=0;j<str.length();j++){
            if(mark[i]==str[j]){
                arr[i]++;
            }
        }
    }
    int max=0;
    int index=-1;
    for(int i=0;i<26;i++){
        if(max<arr[i]+arr[i+26]){
            max = arr[i]+arr[i+26];
            index = i;
        }
    }
    for(int i=0;i<26;i++){
        if(index!=i&&arr[i]+arr[i+26]==max){
            cout << "?";
            return 0;
        }
    }
    cout << mark[index];
    return 0;
}