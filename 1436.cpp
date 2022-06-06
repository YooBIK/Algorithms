#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> vec;
    int count=0;
    int num =0;
    while(count<=n){
        int cont = 1;
        int x = num/10;
        int mod= num%10;
        while(x>0){
            if(x%10==mod&&mod==6){
                cont++;
            }else{
                cont = 1;
            }
            mod = x%10;
            x=x/10;
            if(cont==3){
                vec.push_back(num);
                count++;
                break;
            }
        }
        num++;
    }
    cout<< vec[n-1];
    return 0;
}