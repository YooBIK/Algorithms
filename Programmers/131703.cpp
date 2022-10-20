#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool checker(vector<vector<int>>& temp, vector<vector<int>>& target){
    for(int i=0;i<temp.size();i++){
        for(int j=0;j<temp[0].size();j++){
            if(temp[i][j] != target[i][j]){
                return false;
            }
        }
    }
    return true;
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {

    int row = beginning.size();
    int col = beginning[0].size();
    int answer = 1e9;
    int size = row+col;


    for(int k=0;k< (1<<(size));k++){
        vector<vector<int>> temp = beginning;
        int cnt = 0;
        for(int i=0;i<col;i++){
            if(temp[0][i] != target[0][i]){
                cnt++;
                for(int j=0;j<row;j++){
                    temp[j][i] = 1 - temp[j][i];
                }
            }
        }

        for(int i=0;i<row;i++){
            if(temp[i][0] != target[i][0]){
                cnt++;
                for(int j=0;j<col;j++){
                    temp[i][j] = 1 - temp[i][j];
                }
            }
        }

        
        if(checker(temp,target)){
            answer = min(answer,cnt);
        }
    }

    if(answer == 1e9){
        return -1;
    }else{
        return answer;
    }
    return answer;
    
    

}

