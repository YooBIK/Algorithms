#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
vector<int> dw_list,ks_list;
long long dw_score =0;
long long ks_score =0;
int prime_num[5000001] = {0,};
int check_num[5000001] = {0,};

void init_prime_num(){
    prime_num[0] = -1;
    prime_num[1] = -1;
    for(int i=2;i<=sqrt(5000000);i++){
        if(prime_num[i]==0){
            for(int j=i*i;j<=5000000;j+=i){
                prime_num[j] = -1;
            }
        }
    }
}

int main(){
    init_prime_num();

    // for(int i=0;i<=100;i++){
    //     if(prime_num[i]==0){
    //         cout << i << " "; 
    //     }
    // }
    cin >> n;

    for(int i=0;i<n;i++){
        int dw_prime,ks_prime;
        cin >> dw_prime >> ks_prime;
        if(prime_num[dw_prime]==0){
            if(check_num[dw_prime]==1){
                dw_score -= 1000;
            }
            else{
                dw_list.push_back(dw_prime);
                check_num[dw_prime] = 1;
                sort(dw_list.begin(),dw_list.end());
            }
        }
        else{
            if(ks_list.size()<3){
                ks_score += 1000;
            }
            else{
                ks_score += ks_list[ks_list.size()-3];
            }
        }

        if(prime_num[ks_prime]==0){
            if(check_num[ks_prime]==1){
                ks_score -= 1000;
            }
            else{
                ks_list.push_back(ks_prime); 
                check_num[ks_prime] = 1;
                sort(ks_list.begin(),ks_list.end());
            }   
        }
        else{
            if(dw_list.size()<3){
                dw_score += 1000;
            }
            else{
                dw_score += dw_list[dw_list.size()-3];
            }
        }

    }

    if(dw_score>ks_score){
        cout << "소수의 신 갓대웅";
    }else if(dw_score<ks_score){
        cout << "소수 마스터 갓규성";
    }else{
        cout << "우열을 가릴 수 없음";
    }
    return 0;
}