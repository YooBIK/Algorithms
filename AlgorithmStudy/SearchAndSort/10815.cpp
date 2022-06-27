#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> first_vec;
vector<int> second_vec;
vector<int> result;

int main(){
    int n,m;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        first_vec.push_back(x);
    } 
    sort(first_vec.begin(),first_vec.end());
    cin >> m;
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        second_vec.push_back(x);
    }

    for(int i=0;i<second_vec.size();i++){
        int start =0;
        int end = first_vec.size()-1;

        while(1){
            int mid = (start+end)/2;
            
            if(start>end){
                result.push_back(0);
                break;
            }

            if(second_vec[i] == first_vec[mid]){
                result.push_back(1);
                break;
            }else if(second_vec[i] < first_vec[mid]){
                end = mid - 1;                
            }else{
                start = mid + 1;
            }
        }
    }

    for(int i=0;i<result.size();i++){
        cout << result[i] << " ";
    }

    return 0;
}