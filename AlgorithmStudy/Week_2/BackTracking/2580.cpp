#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sudoku[9][9];
bool row[9][10];
bool col[9][10];
bool smallbox[3][3][10];
vector<pair<int,int>> vec;
bool flag=false;

void print_sudoku(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout <<  sudoku[i][j] << " ";
            
        }
        cout << "\n";
    }
    flag = true;
    return;
}


void dfs(int num){
    if(num == vec.size()){
        print_sudoku();
        return ;
    }

    for(int i=1;i<=9;i++){
        if(flag) return;
        if(sudoku[vec[num].first][vec[num].second] == 0 &&!row[vec[num].first][i] && !col[vec[num].second][i] && !smallbox[vec[num].first / 3][vec[num].second / 3][i]){
            sudoku[vec[num].first][vec[num].second] = i;
            row[vec[num].first][i]= true;
            col[vec[num].second][i]= true;
            smallbox[vec[num].first / 3][vec[num].second / 3][i] = true;
            dfs(num+1);
            row[vec[num].first][i]= false;
            col[vec[num].second][i]= false;
            smallbox[vec[num].first / 3][vec[num].second / 3][i] = false;
            sudoku[vec[num].first][vec[num].second] = 0;
        }
    }
    
}

int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> sudoku[i][j];
            if(sudoku[i][j]==0){
                vec.push_back({i,j});
            }else{
                row[i][sudoku[i][j]] = true;
                col[j][sudoku[i][j]] = true;
                smallbox[i/3][j/3][sudoku[i][j]] = true;
            }
        }
    }
    dfs(0);
    return 0;
}