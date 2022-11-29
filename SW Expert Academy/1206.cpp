#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int map[1004];

int main(){
    vector<int> answerVec;
    for(int i=0;i<10;i++){
        int n;
        cin >> n;
        for(int j=0;j<n;j++){
            cin >> map[j];
        }
        int result = 0;
        for(int j=2;j<n-2;j++){
            int leftMax = max(map[j-1],map[j-2]);
            int rightMax = max(map[j+1],map[j+2]);
            if(leftMax < map[j] && rightMax < map[j]){
                result += map[j] - max(leftMax,rightMax);
            }
        }
        answerVec.push_back(result);
    }

    for(int i=0;i<answerVec.size();i++){
        cout << "#" << i+1 << " " << answerVec[i] << "\n";
    }
}