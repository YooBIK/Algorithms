#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<int> dequeue;
vector<int> result;

int main(){
    int n;
    cin >> n;
    string str;
    getline(cin,str);
    for(int i=0;i<n;i++){
        getline(cin,str);
        if(str=="pop_front"){
            if(dequeue.empty()){
                result.push_back(-1);
            }else{
                result.push_back(dequeue[0]);
                dequeue.erase(dequeue.begin());
            }
        }else if(str == "pop_back"){
            if(dequeue.empty()){
                result.push_back(-1);
            }else{
                result.push_back(dequeue[dequeue.size()-1]);
                dequeue.erase(dequeue.end()-1);
            }
        }else if(str=="size"){
            result.push_back(dequeue.size());
        }else if(str=="empty"){
            if(dequeue.empty()){
                result.push_back(1);
            }else{
                result.push_back(0);
            }
        }else if(str=="front"){
            if(dequeue.empty()){
                result.push_back(-1);
            }else{
                result.push_back(dequeue[0]);
            }
        }else if(str=="back"){
            if(dequeue.empty()){
                result.push_back(-1);
            }else{
                result.push_back(dequeue[dequeue.size()-1]);
            }
        }else{
            stringstream ss;
            ss.str(str);
            string temp;
            ss>>temp;
            if(temp =="push_front"){
                int num;
                ss >> num;
                dequeue.insert(dequeue.begin(),num);
            }else{
                int num;
                ss >> num;
                dequeue.insert(dequeue.end(),num);
            }
        }
    }
    for(int i=0;i<result.size();i++){
        cout << result[i] << "\n";
    }
    return 0;
}