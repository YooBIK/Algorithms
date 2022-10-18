#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";

    //1단계
    for(int i=0;i<new_id.size();i++){
        if('A' <= new_id[i] && new_id[i] <= 'Z'){
            new_id[i] = (char)(new_id[i]+32);
        }
    }

    //2단계
    for(int i=0;i<new_id.size();i++){
        if( ('0'<=new_id[i] && new_id[i]<='9') || ('a'<=new_id[i] && new_id[i]<='z') || new_id[i]=='-' || new_id[i]=='_' || new_id[i]=='.'){

        }else{
            new_id.erase(new_id.begin()+i);
            i--;
        }
    }

    //3단계
    while(new_id.find("..") !=string::npos){
        new_id.erase(new_id.find("..",0),1);
    }

    //4단계
    if(new_id.front() == '.') new_id.erase(new_id.begin()+0);
    if(new_id.back() == '.') new_id.erase(new_id.begin()+new_id.size()-1);

    //5단계
    if(new_id.empty()) new_id.push_back('a');

    //6단계
    if(new_id.size()>15){
        new_id = new_id.substr(0,15);
        if(new_id.back()=='.') new_id.pop_back();
    }
    while(new_id.size()<3){
        new_id.push_back(new_id.back());
    }
    answer=new_id;
    
    return answer;
}