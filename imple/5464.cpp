#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m;
int map[101] = {0,};
int cost[101] = {0,};
int weight[2001] = {0,};
int result = 0;
queue<int> waiting;


void handling(int num){
    if(num > 0){
        for(int i=1;i<=n;i++){
            if(map[i]==0){
                map[i] = num;
                result += weight[num] * cost[i];
                return;
            }
        }
        waiting.push(num);
        return;
    }else if(num < 0){
        for(int i=1;i<=n;i++){
            if(map[i]== -1 * num){
                map[i] = 0;
                if(!waiting.empty()){
                    int new_car = waiting.front();
                    waiting.pop();
                    map[i] = new_car;
                    result += weight[new_car] * cost[i];
                    return;
                }
                return;
            }
        }
    }

}


int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> cost[i];
    }
    for(int i=1;i<=m;i++){
        cin >> weight[i];
    }
    for(int i=0;i<2*m;i++){
        int car_num;
        cin >> car_num;
        handling(car_num);
    }
    cout << result;
    return 0;
}