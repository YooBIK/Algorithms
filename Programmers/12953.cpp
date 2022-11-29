#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool prime[101];

int gcd(int a, int b){
    int result;
    while(b>0){
        result = a%b;
        a= b;
        b= result;
    }
    return result;
}

int lcm(int a, int b){
    return a*b / gcd(a,b);
}


int solution(vector<int> arr) {
    int answer = 0;
    sort(arr.begin(),arr.end());

    answer = arr[0];
    int size = arr.size();
    for(int i=1;i<size;i++){
        answer= lcm(answer,arr[i]);
    }
    return answer;
}