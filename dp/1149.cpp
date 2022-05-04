#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1001][3] = {0,};


int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int r,g,b;
        cin >> r >> g >> b;
        arr[i][0] = min(arr[i-1][1],arr[i-1][2]) + r;
        arr[i][1] = min(arr[i-1][0],arr[i-1][2]) + g;
        arr[i][2] = min(arr[i-1][0],arr[i-1][1]) + b;
    }

    cout << min({arr[n][0],arr[n][1],arr[n][2]});
    return 0;
    
}

// vector<int> vec;
// vector<int> res;
// int arr[1001] = {0,};


// int main(){
//     int n;
//     cin >> n;
//     for(int i=0;i<n;i++){
//         int r,g,b;
//         cin >> r >> g >> b ;
//         vec.push_back(r);
//         vec.push_back(g);
//         vec.push_back(b);
//     }

//     for(int i=0;i<3;i++){
//         arr[1] = vec[i];
//         int result = arr[1];
//         char cur;
//         if(i==0){
//             cur = 'r';
//         }else if(i==1){
//             cur = 'g';
//         }else{
//             cur = 'b';
//         }
//         for(int j=2;j<=n;j++){
//             if(cur=='r'){
//                 arr[j] = min(vec[j*3-1],vec[j*3-2]);
//                 if(arr[j]==vec[j*3-2]){
//                     cur = 'g';
//                 }else{
//                     cur = 'b';
//                 }
//             }else if(cur=='g'){
//                 arr[j] = min(vec[j*3-3],vec[j*3-1]);
//                 if(arr[j]==vec[j*3-3]){
//                     cur = 'r';
//                 }else{
//                     cur = 'b';
//                 }
//             }else{
//                 arr[j] = min(vec[j*3-3],vec[j*3-2]);
//                 if(arr[j]==vec[j*3-3]){
//                     cur = 'r';
//                 }else{
//                     cur = 'g';
//                 }
//             }
//             result += arr[j];
//         }
//         res.push_back(result);
//     }
//     sort(res.begin(),res.end());
//     cout << res[0];
//     return 0;
// }