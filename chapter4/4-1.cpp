#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int n;
    string input;
    cin >> n;
    int i=0;
    int row=1;
    int col=1;
    cin.ignore();
    getline(cin, input);
    for(int i=0;i<input.size();i++){
        switch(input[i])
        {
            case 'R':
                if(col<n){
                  col++;
                }
                i++;
                break;
            case 'L':
                if(col>1){
                    col--;
                }
                i++;
                break;
            case 'U':
                if(row>1){
                    row--;
                }
                i++;
                break;
            case 'D':
                if(row<n){
                    row++;
                }
                i++;
                break;
            default:
                break;
        }
    }
    cout << row << " " << col;
    return 0;
}