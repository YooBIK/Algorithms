#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string temp;
    int index = 0;
    int flag = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            temp.push_back(s[i]);
        }else{
            if(s.substr(i,3) == "one" || s.substr(i,3) == "two" || s.substr(i,3) == "six"){
                if(s.substr(i,3) == "one"){
                    temp.push_back('1');
                }
                if(s.substr(i,3) == "two"){
                    temp.push_back('2');
                }
                if(s.substr(i,3) == "six"){
                    temp.push_back('6');
                }
                i +=2;
            }else if(s.substr(i,4) == "zero" || s.substr(i,4) == "four" || s.substr(i,4) == "five" || s.substr(i,4) == "nine"){
                if(s.substr(i,4) == "zero"){
                    temp.push_back('0');
                }
                if(s.substr(i,4) == "four"){
                    temp.push_back('4');
                }
                if(s.substr(i,4) == "five"){
                    temp.push_back('5');
                }
                if(s.substr(i,4) == "nine"){
                    temp.push_back('9');
                }
                i+=3;
            }else if(s.substr(i,5) == "three" || s.substr(i,5) == "seven" || s.substr(i,5) == "eight"){
                if(s.substr(i,5) == "three"){
                    temp.push_back('3');
                }
                if(s.substr(i,5) == "seven"){
                    temp.push_back('7');
                }
                if(s.substr(i,5) == "eight"){
                    temp.push_back('8');
                }
                i+=4;
            }

        }
        
    }

    answer = stoi(temp);
    return answer;
}