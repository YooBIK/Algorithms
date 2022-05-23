#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string S,T;



void check_is_posible(string str){
    if(str.compare(S)==0){
        cout<<1;
        exit(0);
    }
    if(str.size() <= S.size()){
        return;
    }

    if(str[str.size()-1]=='A'){
        string temp = str;
        temp.erase(temp.size()-1);
        check_is_posible(temp);
    }

    if(str[0]=='B'){
        string temp = str;
        reverse(temp.begin(),temp.end());
        temp.erase(temp.size()-1);
        check_is_posible(temp);
    }
}

int main(){

    cin >> S >> T;
    check_is_posible(T);
    cout << 0;
    return 0;

}