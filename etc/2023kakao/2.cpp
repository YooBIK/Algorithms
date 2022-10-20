#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int curCap = 0;

    while(1){
        curCap = cap;
        int curDelive = cap;
        int curPickups = 0;
        int maxIndex = -1;
        for(int i=n-1;i>=0;i--){
            if(deliveries[i]>0){
                if(deliveries[i]>curDelive){
                    deliveries[i] -= curDelive;
                    curDelive = 0;
                }else{
                    curDelive -= deliveries[i];
                    deliveries[i]==0;
                }
            }

            if(pickups[i]>0){
                if(pickups[i]>curCap-curDelive){
                    curPickups += curCap-curDelive;
                    pickups[i] -= (curCap-curDelive);
                }
            }

        }
        answer += 2*(maxIndex+1);
    }


    return answer;
}