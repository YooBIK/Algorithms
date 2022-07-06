#include <iostream>
#include <vector>

using namespace std;

int n,m;
bool checker[9];
vector<int> temp;
vector<vector<int>> result;

void back_tracking(int k){
    if(k==m){
        result.push_back(temp);

        return;
    }

    for(int i=1;i<=n;i++){
        if(checker[i]==0){
            temp.push_back(i);
            checker[i] = true;
            back_tracking(k+1);
            temp.pop_back();
            checker[i] = false;
        }
    }
}

int main(){
    cin >> n >> m;
    back_tracking(0);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}