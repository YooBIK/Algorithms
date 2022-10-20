#include <iostream>
#include <string>

using namespace std;

int main(){
    string str = "2022.01.01 A";
        string startYear  =str.substr(0,4);
        string startMonth = str.substr(5,2);
        string startDay = str.substr(8,2); 
        int aasdf = str[1] - '0';
    cout <<  aasdf << "\n" <<  startMonth << "\n" << startDay;
}