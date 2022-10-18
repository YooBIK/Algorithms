#include <iostream>
#include <vector>

using namespace std;


bool arr[1001] ;


void check_prime_num(){
    for(int i=0;i<1001;i++) arr[i]=true;
    arr[0] = false;
    arr[1] = false;
    for(int i=2;i*i<=1000;i++){
        if(arr[i]){
            for(int j=2*i;j<=1000;j+=i){
                arr[j]= false;
            }
        }
    }
}

int main(){

    check_prime_num();
    int n;
    vector<int> vec;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }
    int cnt = 0;
    for(int i=0;i<vec.size();i++){
        if(arr[vec[i]]) cnt++;
    }
    cout << cnt ;
    return 0;
}