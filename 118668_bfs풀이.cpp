#include <string>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;


int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = (1<<31)-1;
    queue<tuple<int,int,int>> q;
    q.push({alp,cop,0});
    while(!q.empty()){        
        tuple<int,int,int> curStatus = q.front();
        int curAlp = get<0>(curStatus);
        int curCop = get<1>(curStatus);
        int curDay = get<2>(curStatus);
        q.pop();

        if(curDay>answer){
            continue;
        }

        int canSolve = 0;
        for(int i=0;i<problems.size();i++){
            if(curAlp >= problems[i][0] && curCop >= problems[i][1]){
                canSolve++;
            }
        }
        if(canSolve == problems.size()){
            answer = min(answer,curDay);
            continue;
        }else{
            tuple<int,int,int> temp1 = {curAlp+1,curCop,curDay+1};
            tuple<int,int,int> temp2 = {curAlp,curCop+1,curDay+1};
            q.push(temp1);
            q.push(temp2);
            for(int i=0;i<problems.size();i++){
                if(problems[i][0] <= curAlp && problems[i][1] <= curCop){
                    tuple<int,int,int> temp3 = {curAlp+problems[i][2], curCop+problems[i][3], curDay + problems[i][4]};
                    q.push(temp3);
                }
            }
        }
    }
    return answer;
}