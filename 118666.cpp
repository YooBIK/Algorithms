#include <string>
#include <vector>

using namespace std;



string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    string quest[4] = {"RT","CF","JM","AN"};
    int result[4] = {0,};
    // 경우의 수 : RT TR CF FC JM MJ AN NA
    //1,2,3,4,5,6,7
    for(int i=0;i<survey.size();i++){
        if(survey[i] == "RT" || survey[i] == "TR"){
            if(survey[i] == "RT"){
                result[0] += choices[i]-4;
            }else{
                result[0] -= choices[i]-4;
            }
        }else if(survey[i] == "CF" || survey[i] == "FC"){
            if(survey[i] == "CF"){
                result[1] += choices[i]-4;
            }else{
                result[1] -= choices[i]-4;
            }
        }else if(survey[i] == "JM" || survey[i] == "MJ"){
            if(survey[i] == "JM"){
                result[2] += choices[i]-4;
            }else{
                result[2] -= choices[i]-4;
            }
        }else{
            if(survey[i] == "AN"){
                result[3] += choices[i]-4;
            }else{
                result[3] -= choices[i]-4;
            }
        }
    }

    for(int i=0;i<4;i++){
        if(result[i]<=0){
            answer.push_back(quest[i][0]);
        }else{
            answer.push_back(quest[i][1]);
        }
    }

    return answer;
}