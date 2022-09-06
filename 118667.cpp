#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    queue<long long> q1;
    queue<long long> q2;

    long long q1Sum = 0;
    long long q2Sum = 0;
    for(int i=0;i<queue1.size();i++){
        q1.push(queue1[i]);
        q1Sum += queue1[i];
    }
    for(int i=0;i<queue2.size();i++){
        q2.push(queue2[i]);
        q2Sum += queue2[i];
    }

    if((q1Sum+q2Sum)%2==1){
        return -1;
    }

    int tries = 0;
    while(1){
        if(tries > queue1.size() + queue2.size() + 2){
            answer = -1;
            break;
        }
        if(q1Sum>q2Sum){
            q2.push(q1.front());
            q1Sum -= q1.front();
            q2Sum += q1.front();
            q1.pop();
            tries++;

        }else if(q1Sum<q2Sum){
            q1.push(q2.front());
            q2Sum -= q2.front();
            q1Sum += q2.front();
            q2.pop();
            tries++;
        }else{
            answer = tries;
            break;
        }
    }
    return answer;
}#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    queue<long long> q1;
    queue<long long> q2;

    long long q1Sum = 0;
    long long q2Sum = 0;
    for(int i=0;i<queue1.size();i++){
        q1.push(queue1[i]);
        q1Sum += queue1[i];
    }
    for(int i=0;i<queue2.size();i++){
        q2.push(queue2[i]);
        q2Sum += queue2[i];
    }

    if((q1Sum+q2Sum)%2==1){
        return -1;
    }

    int tries = 0;
    while(1){
        if(tries > queue1.size() + queue2.size() + 2){
            answer = -1;
            break;
        }
        if(q1Sum>q2Sum){
            q2.push(q1.front());
            q1Sum -= q1.front();
            q2Sum += q1.front();
            q1.pop();
            tries++;

        }else if(q1Sum<q2Sum){
            q1.push(q2.front());
            q2Sum -= q2.front();
            q1Sum += q2.front();
            q2.pop();
            tries++;
        }else{
            answer = tries;
            break;
        }
    }
    return answer;
}