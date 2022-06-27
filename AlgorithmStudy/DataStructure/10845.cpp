#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

vector<int> queue_vec;
vector<int> result;

void queue_push(int num){
    queue_vec.push_back(num);
}

void queue_pop(){
    if(queue_vec.empty()){
        result.push_back(-1);
    }else{
        result.push_back(queue_vec[0]);
        queue_vec.erase(queue_vec.begin());
    }
}

void queue_size(){
    result.push_back(queue_vec.size());
}

void queue_empty(){
    if(queue_vec.empty()){
        result.push_back(1);
    }else{
        result.push_back(0);
    }
}

void queue_front(){
    if(queue_vec.empty()){
        result.push_back(-1);
    }else {
        result.push_back(queue_vec[0]);
    }    
}

void queue_back(){
    if(queue_vec.empty()){
        result.push_back(-1);
    }else {
        result.push_back(queue_vec[queue_vec.size()-1]);
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
            queue_pop();
        }else if(temp == "size"){
            queue_size();
        }else if(temp == "front"){
            queue_front();
        }else if(temp=="back"){
            queue_back();
        }else if(temp == "empty"){
            queue_empty();
        }else{
            int num = stoi(temp.substr(4));
            queue_push(num);
        }
    }

    for(int i=0;i<result.size();i++){
        cout << result[i] << "\n";
    }
    return 0;
    
}