#include <iostream>
#include <queue>
#include<functional>
using namespace std;

int n;


priority_queue<int,vector<int>,greater<int>> min_heap;

int main(){
    cin >> n;

    if(n==1){
        cout << 0;
        return 0;
    }

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        min_heap.push(x);
    }

    int result = 0;
    while(min_heap.size()>1){
        int a = min_heap.top();
        min_heap.pop();
        int b = min_heap.top();
        min_heap.pop();
        result += (a+b);
        min_heap.push(a+b);
    }

    cout << result;
    return 0;
    
}