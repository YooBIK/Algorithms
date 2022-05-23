#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> vec;
vector<string> result;
int check[100] = {0,};

bool cmp(string a, string b){
    return a.compare(b) <0;
}

string min_str(){
    sort(vec.begin(),vec.end(),cmp);
    string min_val = vec[0];
    vec.clear();
    return min_val;
}

int main(){

    string str;
    cin >> str;
    string temp1 = str;
    result.push_back(str);
    while(1){
        string temp2 = temp1;
        for(int i=0;i<temp2.length();i++){
            char c = temp2[i];
            temp2.erase(temp2.begin()+i);
            vec.push_back(temp2);
            temp2.insert(temp2.begin()+i,c);
        }
        temp1=min_str();     
        if(temp1.length()==0){
            break;
        }else{
            result.push_back(temp1);
            
        }
    }

    for(int i=result.size()-1;i>=0;i--){
        cout << result[i] << "\n";
    }
    return 0;
}