#include <iostream>
#include <string>

using namespace std;

int n,m;
string arr[50];

int check_area(){
    int max_area =1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int area = 1;
            for(int k=j;k<m;k++){
                int length = k-j;
                if(i+length<n && arr[i][j]==arr[i][k] && arr[i][j]==arr[i+length][j] && arr[i][j]==arr[i+length][k]){
                    area = (length+1)*(length+1);
                }
            }
            if(area>max_area){
                max_area = area;
            }
        }
    }
    return max_area;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << check_area();

    return 0;
}