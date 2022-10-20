#include <string>
#include <vector>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    
    vector<int> answer;
    for(int i=0;i<privacies.size();i++){
        int startYear  = stoi(privacies[i].substr(0,4));
        int startMonth = stoi(privacies[i].substr(5,2));
        int startDay = stoi(privacies[i].substr(8,2));

        char type = privacies[i][11];

        int duration;
        for(int j=0;j<terms.size();j++){
            if(type == terms[j][0]){
                duration = stoi(terms[j].substr(2));
                break;
            }
        }

        string endDate;

        int endYear;
        int endMonth;
        int endDay = startDay-1;

        endMonth = startMonth + duration;
        
        if(endMonth>12){
            endYear = startYear + endMonth / 12;
            endMonth = endMonth % 12;
        }else{
            endYear = startYear;
        }

        if(endDay==0){
            endDay = 28;
            endMonth--;
        }


        string endYear_string = to_string(endYear);
        string endMonth_string = to_string(endMonth);;
        string endDay_string = to_string(endDay);;
        if(endMonth_string.length() == 1){
            endMonth_string = "0" + endMonth_string;
        }

        if(endDay_string.length() == 1){
            endDay_string = "0" + endDay_string;
        }


        endDate = endYear_string + "." + endMonth_string + "." + endDay_string;

        if(endDate<today){
            answer.push_back(i+1);
        }  
    }
    return answer;
}