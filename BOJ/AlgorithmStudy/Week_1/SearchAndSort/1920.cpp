#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n,m;
vector<int> vec_n;
vector<int> vec_m;
vector<int> result;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        vec_n.push_back(x);
    }
    sort(vec_n.begin(),vec_n.end());

    cin >> m;
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        vec_m.push_back(x);
    }

    for(int i=0;i<vec_m.size();i++){
        int start = 0;
        int end = vec_n.size()-1;        
        while(1){
            int mid = (start+end) / 2;
            if(end<=start){
                if(vec_n[mid]==vec_m[i]){
                    result.push_back(1);
                    break;
                }else{
                    result.push_back(0);
                    break;
                }
            }

            if(vec_n[mid]>vec_m[i]){
                end = mid-1;
            }else if(vec_n[mid]<vec_m[i]){
                start = mid+1;
            }else{
                result.push_back(1);
                break;
            }
        }
    }

    for(int i=0;i<result.size();i++){
        cout << result[i] << "\n";
    }

    return 0;
}