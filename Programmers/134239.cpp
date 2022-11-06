#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<double> area;
    area.push_back(0);
    while(k!=1){
        double before = k;
        if(k%2==1){
            k = k*3 +1;
        }else{
            k /= 2;
        }
        area.push_back( (double)(k+before) /2 );
    }

    for(int i=0;i<area.size();i++){
        cout << area[i] << " ";
    }


    for(int i=0;i<ranges.size();i++){
        int startIndex = ranges[i][0];
        int endIndex = area.size() -1 + ranges[i][1];
        if(endIndex<startIndex){
            answer.push_back(-1);
        }else{
            double result = 0;
            for(int j=startIndex+1;j<=endIndex;j++){
                result += area[j];
            }
            answer.push_back(result);
        }
        
    }
    return answer;
}