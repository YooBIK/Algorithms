#include <iostream>
#include <queue>
#include <functional>

using namespace std;

priority_queue<int,vector<int>,less<int>> max_heap;
vector<int> result;

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x==0){
            if(max_heap.empty()){
                result.push_back(0);
            }
            else{
                result.push_back(max_heap.top());
                max_heap.pop();
            }
        }else{
            max_heap.push(x);
        }
    }
    for(int i=0;i<result.size();i++){
        cout << result[i] << "\n";
    }
    return 0;
}