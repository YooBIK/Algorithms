#include <iostream>
#include <queue>
#include <cmath>


using namespace std;
struct comp{
    bool operator()(int a,int b){
        if(abs(a)==abs(b)){
            return a>b;
        }else{
            return abs(a)>abs(b);
        }
    }
};

priority_queue<int,vector<int>,comp> abs_min_heap;
vector<int> result;
int main(){
    int n;
    cin >>n;
    for(int i=0;i<n;i++){
        int x;
        cin>> x;
        if(x==0){
            if(abs_min_heap.empty()){
                result.push_back(0);
            }else{
                result.push_back(abs_min_heap.top());
                abs_min_heap.pop();
            }
        }else{
            abs_min_heap.push(x);
        }
    }

    for(auto x : result){
        cout << x << "\n";
    }
    return 0;
}