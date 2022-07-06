#include<iostream>
#include <cmath>
using namespace std;

int main(){
    int ntest;
    cin >>ntest;
    for(int i=0;i<ntest;i++){
        int x1,x2,y1,y2,r1,r2;
        cin >>x1>>y1>>r1>>x2>>y2>>r2;
        int t1 = (r1+r2)*(r1+r2);
        int t2 = (r1-r2)*(r1-r2);
        double dist = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        if(dist==0){
            if(t2==0){
                cout <<"-1" <<"\n";
            }else{
                cout << "0"<<"\n";
            }
        }else if(dist==t1||dist==t2){
            cout <<"1"<<"\n";
        }else if(dist<t1&&dist>t2){
            cout <<"2"<<"\n";
        }else{
            cout <<"0"<<"\n";
        }
    }
    return 0;
}