#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int count=0;
    for(int i=0;i<n;i++){
        int num;
        int count_mul=0;
        cin >> num;
        for(int j=1;j<=num;j++){
            if(num%j==0){
                count_mul++;
            }
        }
        if(count_mul==2){
            count++;
        }
    }
    cout << count;
    return 0;
}