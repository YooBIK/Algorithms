#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

string s,e,q;
set<string> start_check;
set<string> end_check;
int result =0;
int string_to_int(string chat_time){
    string str= chat_time.substr(0,2) + chat_time.substr(3,2);
    return stoi(str);
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> s >> e >> q;
    int start_time =string_to_int(s);
    int end_time = string_to_int(e);
    int quit_time = string_to_int(q);
    
    string chat_time,id;

    while(cin >> chat_time >> id){
        int i_chat_time = string_to_int(chat_time);
        if(chat_time<=s){
            start_check.insert(id);
            continue;
        }
        if(i_chat_time>=end_time && i_chat_time <= quit_time){
            if(start_check.find(id)!=start_check.end()){
                end_check.insert(id);   
            }
        }
    }
    cout << end_check.size();

    return 0;
}