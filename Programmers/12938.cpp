#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(s<n){
        answer.push_back(-1);
        return answer;
    }

    int share = s / n;
    int mod = s % n;
    for(int i=0;i<n;i++){
        answer.push_back(share);
    }
    for(int i=answer.size()-1;i>=0;i--){
        if(mod == 0){
            break;
        }
        answer[i] += 1;
        mod--;
    }
    return answer;
}