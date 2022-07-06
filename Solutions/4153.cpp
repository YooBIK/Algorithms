#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    while(1){
        int x,y,z;
        cin >> x>>y>>z;
        if(x==0&&y==0&&z==0){
            break;
        }
        if(x==max({x,y,z})){
        if(x*x==y*y+z*z){
            cout << "right" <<"\n";
        }else{
            cout <<"wrong"<<"\n";
        }        
        }
        else if(y==max({x,y,z})){
            if(y*y==x*x+z*z){
                cout << "right" <<"\n";
            }else{
                cout <<"wrong"<<"\n";
            }     
        }
        else{
            if(z*z==y*y+x*x){
                cout << "right" <<"\n";
            }else{
                cout <<"wrong"<<"\n";
            }     
        }
    }
    return 0;
}