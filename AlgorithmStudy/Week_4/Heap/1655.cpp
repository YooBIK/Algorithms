#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int n;
priority_queue<int,vector<int>,greater<int>> min_heap;
priority_queue<int,vector<int>,less<int>> max_heap;
vector<int> vec;
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }

    for(int i=0;i<vec.size();i++){
        if(max_heap.size()>min_heap.size()){
            min_heap.push(vec[i]);
        }else{
            max_heap.push(vec[i]);
        }

        if(min_heap.empty() || max_heap.empty()){
            
        }else{
            if(min_heap.top()<max_heap.top()){
                int a = min_heap.top();
                min_heap.pop();
                int b = max_heap.top();
                max_heap.pop();
                max_heap.push(a);
                min_heap.push(b);
            }
        }
        cout << max_heap.top() << "\n";
    }
    return 0;
}