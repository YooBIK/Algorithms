#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    queue<int> q; 
    stack<int> temp;

    for(int i=1;i<=order.size();i++){
        q.push(i);
    }

    for(int i=0;i<order.size();i++){
        if(temp.empty()){
            if(q.front()<=order[i]){
                while(1){
                    if(q.front()==order[i]){
                        answer++;
                        q.pop();
                        break;
                    }else{
                        temp.push(q.front());
                        q.pop();
                    }
                }
            }else{
                break;
            }
            
        }else{
            if(temp.top()==order[i]){
                temp.pop();
                answer++;
                continue;
            }else{
                if(q.front()<=order[i]){
                    while(1){
                        if(q.front()==order[i]){
                            q.pop();
                            answer++;
                            break;
                        }else{
                            temp.push(q.front());
                            q.pop();
                        }
                    }
                }else{
                    break;
                }
            }

        }
    }
    return answer;  
    
}