#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[20][20] = {0,};
bool team[20];

int result = 99999999;

int carc(){

    int sum_team_true=0;
    int sum_team_false=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(team[i]==team[j]){
                if(team[i]){
                    sum_team_true += arr[i][j]; 
                }else{
                    sum_team_false += arr[i][j];
                }
            }
        }
    }
    if(sum_team_true>sum_team_false){
        return sum_team_true - sum_team_false;
    }else{
        return sum_team_false - sum_team_true;
    }
}


void dfs(int start, int num){
    if(num == n/2){
        result = min(result, carc());
        return ;
    }
    for(int i=start;i<n;i++){
        if(!team[i]){
            team[i] = true;
            dfs(i,num+1);
            team[i]= false;
        }
    }
}

int main(){
    cin >> n;
    if(n<4 || n>20 || n%2 == 1 ) return 0;


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    dfs(0,0);
    cout << result;
    return 0;
}
