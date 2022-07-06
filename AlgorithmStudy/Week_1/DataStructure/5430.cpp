#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <list>
using namespace std;


vector<string> result;


int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        string cnd;
        cin >> cnd;
        int n;
        cin >> n;
        string arr;
        cin >> arr;

        arr.erase(arr.begin());
        arr.erase(arr.end()-1);

        stringstream ss(arr);
        string temp;
        list<string> num_arr;

        while(getline(ss, temp, ',')){
            num_arr.push_back(temp);
        }        

        int error_flag =0;
        bool is_reverse = false;
        for(int j=0;j<cnd.length();j++){
            if(cnd[j]=='R'){
                is_reverse= !is_reverse;
            }else{
                if(num_arr.empty()){
                    result.push_back("error");
                    error_flag=1;
                    break;
                }else{
                    if(is_reverse){
                        num_arr.pop_back();
                    }else{
                        num_arr.pop_front();
                    }
                }
            }
        }
        if(error_flag){
            continue;
        }else{
            if(num_arr.empty()){
               result.push_back("[]"); continue; 
            }

            if(is_reverse){
                string temp;
                temp.push_back('[');
                while(!num_arr.empty()){
                    temp+=num_arr.back();
                    num_arr.pop_back();
                    temp.push_back(',');
                }
                temp.pop_back();
                temp.push_back(']');
                result.push_back(temp);
            }else{
                string temp;
                temp.push_back('[');
                while(!num_arr.empty()){
                    temp+=num_arr.front();
                    num_arr.pop_front();
                    temp.push_back(',');
                }
                temp.pop_back();
                temp.push_back(']');
                result.push_back(temp);
            }       
        }
    }

    for(int i=0;i<result.size();i++){
        cout << result[i] << "\n";
    }

    return 0;
}