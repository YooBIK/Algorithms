#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

vector<int> stack_vec;
vector<int> result;

void stack_push(int num){
    stack_vec.push_back(num);
}

void stack_pop(){
    if(stack_vec.empty()){
        result.push_back(-1);
    }else{
        result.push_back(stack_vec[stack_vec.size()-1]);
        stack_vec.erase(stack_vec.end()-1);
    }
}

void stack_size(){
    result.push_back(stack_vec.size());
}

void stack_empty(){
    if(stack_vec.empty()){
        result.push_back(1);
    }else{
        result.push_back(0);
    }
}

void stack_top(){
    if(stack_vec.empty()){
        result.push_back(-1);
    }else {
        result.push_back(stack_vec[stack_vec.size()-1]);
    }    
}



int n;

int main(){
    cin >> n;
    string temp;
    getline(cin,temp);
    for(int i=0;i<n;i++){
        getline(cin,temp);
        if(temp == "pop"){
            stack_pop();
        }else if(temp == "size"){
            stack_size();
        }else if(temp == "top"){
            stack_top();
        }else if(temp == "empty"){
            stack_empty();
        }else{
            int num = stoi(temp.substr(4));
            stack_push(num);
        }
    }

    for(int i=0;i<result.size();i++){
        cout << result[i] << "\n";
    }
    return 0;
    
}