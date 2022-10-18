#include <iostream>
#include <vector>
using namespace std;
vector<int> vec;
int arr[11] = {0,};


int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        arr[1] = 1; 
        arr[2] = 2;
        arr[3] = 4;        
        for(int j=4;j<=n;j++){
            arr[j]= arr[j-1]+arr[j-2]+arr[j-3];
        }
        vec.push_back(arr[n]);

    }
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << "\n" ;
    }
    return 0;
}