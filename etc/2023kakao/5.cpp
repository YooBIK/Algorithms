#include <string>
#include <vector>
#include <sstream>
using namespace std;


string excel[51][51];
int mergeChecker[51][51];


vector<string> solution(vector<string> commands) {
    vector<string> answer;
    int mergeNumber = 0;
    for(int i=0;i<commands.size();i++){
        stringstream ss;
        ss.str(commands[i]);
        string com;
        ss >> com;
        if(com == "UPDATE"){
            int r;
            int c;
            string value;
            ss >> r >> c >> value;
            if(!value.empty()){
                if(mergeChecker[r][c] ==0){
                    excel[r][c] = value;
                }else{
                    for(int j=1;j<=50;j++){
                        for(int k=1;k<=50;k++){
                            if(mergeChecker[j][k] == mergeChecker[r][c]){
                                excel[j][k] = value;
                            }
                        }
                    }
                }

            }else{
                string before = to_string(r);
                string after = to_string(c);
                for(int j=1;j<=50;j++){
                    for(int k=1;k<=50;k++){
                        if(excel[j][k] == before){
                            excel[j][k] = after;
                        }
                    }
                }
            }
        }else if(com == "MERGE"){            
            int b_r,b_c,a_r,a_c;
            ss >> b_r >> b_c >> a_r >> a_c;
            if(mergeChecker[b_r][b_c] == 0 && mergeChecker[a_r][a_c] == 0){              
                mergeNumber++;
                mergeChecker[b_r][b_c] = mergeNumber;
                mergeChecker[a_r][a_c] = mergeNumber;
                excel[a_r][a_c] = excel[b_r][b_c];
            }else{                                                                                                 
                if(mergeChecker[a_r][a_c] == 0){                                    
                    mergeChecker[a_r][a_c] = mergeChecker[b_r][b_c];
                    excel[a_r][a_c] = excel[b_r][b_c];
                }else{                                                              
                    if(mergeChecker[b_r][b_c]==0){                                  
                        mergeNumber++;
                        mergeChecker[b_r][b_c] = mergeNumber;
                        for(int j=1;j<=50;j++){
                            for(int k=1;k<=50;k++){
                                if(mergeChecker[j][k]==mergeChecker[a_r][a_c]){
                                    mergeChecker[j][k] = mergeNumber;
                                    excel[j][k] = excel[b_r][b_c];
                                }
                            }
                        }
                    }else{                                                          
                        int num = mergeChecker[a_r][a_c];
                        for(int j=1;j<=50;j++){
                            for(int k=1;k<=50;k++){
                                if(mergeChecker[j][k] == num){
                                    mergeChecker[j][k] = mergeChecker[b_r][b_c];
                                    excel[j][k] = excel[b_r][b_c];
                                }
                            }
                        }
                    }
                }                
            }

        }else if(com == "UNMERGE"){
            int r,c;
            ss >> r >> c;
            string val = excel[r][c];
            if(mergeChecker[r][c]==0) continue;

            

            for(int j=1;j<=50;j++){
                for(int k=1;k<=50;k++){
                    if(mergeChecker[r][c]!=0 && mergeChecker[j][k] == mergeChecker[r][c]){
                        mergeChecker[j][k] = 0;
                        excel[j][k] = "";
                    }
                }
            }
            excel[r][c] = val;

        }else if(com == "PRINT"){
            int r,c;
            ss >> r >> c;
            if(excel[r][c].empty()){
                answer.push_back("EMPTY");
            }else{
                answer.push_back(excel[r][c]);
            }
        }
    }
    return answer;
}