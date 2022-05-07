#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;

int arr[6] = {500,100,50,10,5,1};

int main(){
    int n;
    cin >> n;
    int change = 1000-n;
    int count =0;

    for(int i=0;i<6;i++){
        if(change>=arr[i]){
            count += change/arr[i];
            change = change%arr[i];
        }
    }
    cout << count;
    return 0;
}