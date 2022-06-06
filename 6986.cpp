#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,k;
vector<double> vec;

int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        double x;
        cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(),vec.end());
    double sum1=0,sum2=0,avg1=0,avg2=0;
    for(int i=0;i<k;i++){
        sum2 += vec[k];
    }

    for(int i=vec.size()-1;i>vec.size()-1-k;i--){
        sum2 += vec[vec.size()-1-k];
    }

    for(int i=k;i<vec.size()-k;i++){
        sum1 += vec[i];
        sum2 += vec[i];
    }
    avg1 = sum1 / (n-(2*k));
    avg2 = sum2 / n;
    cout << fixed;
    cout.precision(2);
    printf("%.2lf\n", avg1 + 0.00000001);
    printf("%.2lf\n", avg2 + 0.00000001);



    return 0;
}