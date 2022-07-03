#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> num_list;
vector<char> result;

int main(){
    cin >> n;
    stack<int> num_stack;
    queue<int> num_queue;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        num_list.push_back(x);
        num_stack.push(n-i+1);
    }

    stack<int> temp;

    for(int i=0;i<num_list.size();i++){
        if(temp.empty() && !num_stack.empty()){
            temp.push(num_stack.top());
            num_stack.pop();
            result.push_back('+');
        }
        if(num_list[i]>temp.top()){
            if(num_stack.top()>num_list[i]){
                cout << "NO";
                return 0;
            }
            while(1){
                if(temp.top()==num_list[i]){
                    temp.pop();
                    result.push_back('-');
                    break;
                }else{
                    temp.push(num_stack.top());
                    num_stack.pop();
                    result.push_back('+');
                }                
            }
        }else if(num_list[i]<temp.top()){
            cout << "NO";
            return 0;
        }else{
            temp.pop();
            result.push_back('-');
        }  
    }


    for(int i=0;i<result.size();i++){
        cout << result[i] << "\n";
    }
    return 0;
}