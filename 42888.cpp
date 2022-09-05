#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string,vector<pair<string,string>>> hist;
    unordered_map<string,string> userId_nickName;
    for(int i=0;i<record.size();i++){
        stringstream ss;
        ss.str(record[i]);
        string command;
        string userId;
        string nickName;
        ss >> command;
        ss >> userId;
        ss >> nickName;
        hist[userId].push_back({command,nickName});
    }
    for(auto x : hist){
        for(int i=x.second.size()-1;i>=0;i--){
            if(x.second[i].first=="Enter" || x.second[i].first=="Change"){
                userId_nickName[x.first] = x.second[i].second;
                break;
            }
        }
    }

    for(int i=0;i<record.size();i++){
        stringstream ss;
        ss.str(record[i]);
        string command;
        string userId;
        string nickName;
        ss >> command;
        ss >> userId;
        ss >> nickName;
        if(command=="Enter"){
            answer.push_back(userId_nickName[userId]+"님이 들어왔습니다.");
        }else if(command=="Leave"){
            answer.push_back(userId_nickName[userId]+"님이 나갔습니다.");
        }
    }    
    return answer;
}