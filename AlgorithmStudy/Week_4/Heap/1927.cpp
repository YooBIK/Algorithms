#include <iostream>
#include <queue>
#include <functional>

using namespace std;

bool comp(int a, int b){
    return a<b;
}


priority_queue<int,vector<int>,greater<int>> min_heap;
vector<int> result;
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x==0){
            if(min_heap.empty()){
                result.push_back(0);
            }
            else{
                result.push_back(min_heap.top());
                min_heap.pop();
            }
        }else{
            min_heap.push(x);
        }
    }

    for(int i=0;i<result.size();i++){
        cout << result[i] << "\n";
    }
    return 0;
}