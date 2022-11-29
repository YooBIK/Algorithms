#include <iostream>
#include <string>
using namespace std;

int main(){
    string input;
    cin >> input;
    int x[8]={2,2,-2,-2,1,1,-1,-1};
    int y[8]={1,-1,1,-1,2,-2,2,-2};
    int row= input[1]-'0';
    int col = input[0] - 'a' +1;
    int result=0;
    for(int i=0;i<8;i++){
        int newcol = col + x[i];
        int newrow = row+ y[i];
        if(newcol>0&&newcol<=8&&newrow>0&&newcol<=8){
            result++;
        }
    }
    cout << result;
    return 0;
}