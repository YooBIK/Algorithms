#include <string>
#include <vector>
#include <cmath>

using namespace std;
string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int,int> leftCurrent = {3,0};
    pair<int,int> rightCurrent = {3,2};
    for(int i=0;i<numbers.size();i++){
        if(numbers[i]==1 || numbers[i]==4 || numbers[i]==7){
            answer.push_back('L');
            leftCurrent = {(numbers[i]-1)/3,(numbers[i]-1)%3};
            continue;
        }else if(numbers[i]==3 || numbers[i]==6 || numbers[i]==9){
            answer.push_back('R');
            rightCurrent = {(numbers[i]-1)/3,(numbers[i]-1)%3};
        }else{
            pair<int,int> numberPos = {(numbers[i]-1)/3,(numbers[i]-1)%3};
            if(numbers[i]==0){
                numberPos = {3,1};
            }            
            int leftDist = abs(leftCurrent.first - numberPos.first) + abs(leftCurrent.second - numberPos.second); 
            int rightDist = abs(rightCurrent.first - numberPos.first) + abs(rightCurrent.second - numberPos.second);
            if(leftDist < rightDist){
                answer.push_back('L');
                leftCurrent = numberPos;
            }else if(leftDist > rightDist){
                answer.push_back('R');
                rightCurrent = numberPos;
            }else{
                if(hand=="right"){
                    answer.push_back('R');
                    rightCurrent = numberPos;
                }else{
                    answer.push_back('L');
                    leftCurrent = numberPos;    
                }
            }

        }
    }

    return answer;
}