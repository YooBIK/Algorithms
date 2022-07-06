#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a,string b){
    if(a.length()==b.length()){
        return a<b;
    }else{
        return a.length()<b.length();
    }
}

int main(){
    int n;
    cin >> n;
    vector<string> vec;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        vec.push_back(str);
    }
   
   sort(vec.begin(),vec.end(),compare);
   

    for(int i=0;i<vec.size();i++){
        if(vec[i]!=vec[i+1]){
            cout << vec[i] << "\n";
        }
    }
    return 0;
}