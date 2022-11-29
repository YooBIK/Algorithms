#include <vector>

using namespace std;

int countOnes(int num){
    int count = 0;
    while(num>0){
        if(num%2 == 1){
            count++;
        }
        num /= 2;
        
    }
    return count;
}

int solution(int n) {
    int answer = 0;
    int target = countOnes(n);
    for(int i=n+1;i<=1000000;i++){
        if(countOnes(i)==target){
            answer = i;
            break;
        }
    }
    return answer;
}

