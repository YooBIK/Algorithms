#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string str;
    cin >> str;
    string letter;
    vector<int> number;
    for(int i=0;i<str.length();i++){
        if(str[i]>=65&&str[i]<=90){
            letter.push_back(str[i]);
        }else{
            number.push_back(str[i]-'0');
        }
    }
    sort(number.begin(),number.end());
    sort(letter.begin(),letter.end());
    int sum =0;
    for(int i=0;i<number.size();i++){
        sum += number[i];
    }
    cout  << letter << sum;
    return 0;
}