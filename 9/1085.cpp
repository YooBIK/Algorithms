#include <iostream>
using namespace std;

int main(){
    int x,y,w,h;
    cin >> x>>y>>w>>h;
    int xmin,ymin;
    if((w-x)<x){
        xmin = w-x;
    }else{
        xmin =x;
    }
    if((h-y)<y){
        ymin = h-y;
    }else{
        ymin =y;
    }
    if(xmin<ymin){
        cout << xmin;
    }else{
        cout << ymin;
    }
    return 0;

}