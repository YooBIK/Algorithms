#include <iostream>
using namespace std;

int main(){
    int ntest;
    cin >> ntest;
    for(int j=0;j<ntest;j++){
        long long x,y,result;
        cin >> x>>y;
        long long i=1;

        for(;;i++){
            if(y-x<i*i){break;}
        }
        if(y-x==(i-1)*(i-1)){
            result = 2*(i-1)-1;
        }
        else if(y-x<=((i-1)*(i-1)+i*i)/2){
            result = 2*(i-1);
        }else{
            result = 2*i-1;
        }
        cout << result << "\n";
    }
    return 0;
}