#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> vec;

bool compare(string a, string b){
    if(a.length()==b.length()){
        return a<b;
    }else{
        return a.length()< b.length();
    }
}


int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        vec.push_back(str);
    }

    sort(vec.begin(),vec.end(),compare);
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << "\n";
    }
    return 0;
}