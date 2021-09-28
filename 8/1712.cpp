#include <iostream>

using namespace std;

int main(){
    long long a,b,c;
    cin >> a>>b>>c;
    if(b>=c){
        cout << "-1";
    }else{
        long long n = a/(c-b);
        cout << n+1;
    }
    return 0;
}