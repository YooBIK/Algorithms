#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    vector<int> vec;
    cin >> n;
    if(n==1){
        return 0;
    }else{
        for(int i=2;i<=n;){
            if(n%i==0){
                vec.push_back(i);
                n/=i;
            }else{
                i++;
            }
        }
    }
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << "\n";
    }
    return 0;
}