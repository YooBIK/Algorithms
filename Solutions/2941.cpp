#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string str;
    int index;
    vector<string> cro = {"c=","c-","dz=","d-","lj","nj","s=","z="};
    cin >>str;
    int result = str.length();
    for(int i=0;i<cro.size();i++){
        while(1){
            index = str.find(cro[i]);
            if(index == string::npos){
                break;
            }else{
                str.replace(index,cro[i].length(),"@");
            }
        }
    }
    cout << str.length();
}