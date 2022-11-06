#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(long long a , long long b){
    return a>b;
}

long long solution(int n, vector<int> works) {
    long long answer = 0;
    sort(works.begin(),works.end(),compare);
    bool flag = false;
    while(!flag){
        int index = works.size();
        for(int i=1;i<works.size();i++){
            if(works[0] != works[i]){
                index = i;
                break;
            }
        }

        for(int i=0;i<index;i++){
            works[i]--;
            n--;
            if(n==0 || (works[i]==0 && i==index-1)){
                flag=true;
                break;
            }
        }

    }

    for(int i : works){
        cout << i << " ";
        answer += i*i;
    }


    return answer;
}