#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

bool is_prime(long long n){
    if(n==1) return false;
    for(long long i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}


int main(){


    string str,rev_str;
    cin >> str;
    long long num1,num2;
    for(int i=str.length()-1;i>=0;i--){
        if(str[i]=='6'){
            rev_str.push_back('9');
        }
        else if(str[i]=='9'){
            rev_str.push_back('6');
        }
        else if(str[i]=='0'||str[i]=='1'||str[i]=='2'||str[i]=='5'||str[i]=='8'){
            rev_str.push_back(str[i]);
        }
        else{
            cout << "no";
            return 0;
        }
    }
    num1 = stoll(str);
    num2 = stoll(rev_str);


    if(is_prime(num1)&&is_prime(num2)){
        cout << "yes";
    }else{
        cout << "no";
    }
    return 0;
}
    
    // cout << num1 << "\n" << num2 ;
    // if(is_prime(num1)){
    //     for(int i=str.length()-1;i>=0;i--){
    //         rev_str.push_back(str[i]);
    //     }
    //     for(int i=0;i<rev_str.length();i++){
    //         if(rev_str[i]=='6') rev_str[i] = '9';
    //         if(rev_str[i]=='9') rev_str[i] = '6';
    //     }
    //     num2 = stoll(rev_str);
    //     if(is_prime(num2)){
    //         cout << "yes";
    //     }else{
    //         cout << "no";
    //     }
    // }else{
    //     cout << "no";
    // }
//     return 0;
// }