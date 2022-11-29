#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    unordered_map<string,bool> usedWords;
    int round = 0;
    int index = 0;
    bool breakFlag = false;
    string lastWord = words[0];
    usedWords[lastWord] = true;

    for(int i=1;i<words.size();i++){
        if(words[i][0] != lastWord[lastWord.length()-1] || words[i].length() ==1 || usedWords[words[i]]){
            answer.push_back((i%n)+1);
            answer.push_back((i/n)+1);
            break;
        }else{
            usedWords[words[i]] = true;
            lastWord = words[i];
        }
    }
    
    if(answer.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}