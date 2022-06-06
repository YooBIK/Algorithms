#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int arr[8001] = {0,};
    vector<int> list;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        arr[x+4000]++;
        list.push_back(x);
    }
    sort(list.begin(),list.end());
    int sum=0;
    for(int i=0;i<n;i++){
        sum += list[i];
    }
    int avg = round((double)sum/n);

    int max_count = 0;
    int check = 0 ;
    vector<int> most_num;
    int most;
    for(int i=0;i<8001;i++){
        if(arr[i]>max_count){
            max_count = arr[i];
        }
    }
    for(int i=0;i<8001;i++){
        if(arr[i]==max_count){
            most_num.push_back(i-4000);
        }
    }
    if(most_num.size()==1){
        most = most_num[0];
    }else{
        most = most_num[1];
    }
      
    int mid = list[n/2];
    int range = list.back() - list.front();

    cout << avg << "\n";
    cout << mid << "\n";
    cout << most << "\n";
    cout << range ;

    return 0;
}