#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string board[50];
string asw1[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};
string asw2[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

int check1(int r, int c){
    int count=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i+r][j+c]!=asw1[i][j]){
                count++;
            }
        }
    }
    return count;
}

int check2(int r,int c){
    int count=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i+r][j+c]!=asw2[i][j]){
                count++;
            }
        }
    }
    return count;
}

int main(){
    int n,m;
    int result = 50*50;
    cin >> n >> m;
    int rowoffset = n-8; 
    int coloffset = m-8;
    for(int i=0;i<n;i++){
        cin >> board[i];
    }
    for(int r=0;r<=rowoffset;r++){
        for(int c=0;c<=coloffset;c++){
            int x = min(check1(r,c),check2(r,c));
            if(x<result){
                result = x;
            }
        }
    }
    cout << result ;
    return 0;
}