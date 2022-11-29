#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;

int main(){
    vector<int> resultVec;
    for(int i=0;i<10;i++){
        vector<int> vec;
        int dump;
        cin >> dump;
        for(int i=0;i<100;i++){
            int temp;
            cin >> temp;
            vec.push_back(temp);
        }
        while(dump>0){
            sort(vec.begin(),vec.end());
            vec[vec.size()-1]--;
            vec[0]++;
            dump--;
        }
        sort(vec.begin(),vec.end());
        resultVec.push_back(vec[vec.size()-1]-vec[0]);
    }
    for(int i=0;i<resultVec.size();i++){
        cout << "#" << i+1 << " " << resultVec[i] << "\n";
    }
}