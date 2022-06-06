#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> list;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        list.push_back(x);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(list[j]>list[j+1]){
                int x = list[j+1];
                list[j+1]=list[j];
                list[j]=x;
            }
        }
    }
    for(int i=0;i<list.size();i++){
        cout << list[i] << "\n";
    }
    return 0;
}