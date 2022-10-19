#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) { //substr함수 사용 중요!!
    int mid = s.length()/2;
    vector<int> vec;
    vec.push_back(s.length());
    
    for(int i=1;i<=mid;i++){
        int len = s.length();
        int p=0;
        while(1){
            string part = s.substr(p,i);
            p+=i;
            if(p>=s.length())break;            
            int count =0;
            while(1){
                if(part == s.substr(p,i)){
                    p+=i;
                    count++;
                }else{
                    break;
                }
            } 
            if(count>0) {
                len -= i*count;
                if(count<9) len +=1;
                else if(count<99) len+=2;
                else if(count<999) len+=3;
                else len+=4; 
                
            }
        }
        vec.push_back(len);
        sort(vec.begin(),vec.end());
    } 
    return vec[0];
}