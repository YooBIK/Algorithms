#include <iostream>
#include <vector>
using namespace std;

bool test(int n);

int main(){
    int n;
    int count=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        if(test(i)==true){
            count++;
        }
    }
    cout << count;
    return 0;
}

bool test(int n){
    vector<int> cont; 
    while(n>0){
        int x=n;
        x = n%10;
        cont.push_back(x);
        n /= 10;
    }
    if(cont.size()<3){
        return true;
    }
    int num1 = cont.back();
    cont.pop_back();
    int num2 = cont.back();
    cont.pop_back();
    int num3 = cont.back();
    cont.pop_back();
    int gap1 = num1 - num2;
    int gap2 = num2 - num3;
    if(gap1==gap2){
        return true;
    }else{
        return false;
    }
}