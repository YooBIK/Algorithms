#include <iostream>
#include <vector>
using namespace std;

int main(){
    int m,n;
    cin >> m>>n;
    vector<int> vec;
    for(int i=m;i<=n;i++){
        int count=0;
        for(int j=1;j<=i;j++){
            if(i%j==0){
                count++;
            }
        }
        if(count==2){
            vec.push_back(i);
        }
    }
    if(vec.empty()){
        cout << -1;
    }else{
        int sum=0;
        int min= vec.front();
        for(int i=0;i<vec.size();i++){
            sum+=vec[i];
        }
        cout << sum << "\n" << min;
    }
    return 0;
}