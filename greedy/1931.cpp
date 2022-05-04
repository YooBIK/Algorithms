    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <vector>

    using namespace std;

    bool compare(pair<int,int>& a,pair<int,int>& b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second<b.second;
    }

    int main(){
        int n;
        cin >>n;
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            int a,b;
            cin >> a >> b;
            vec.push_back(make_pair(a,b));
        }
        sort(vec.begin(),vec.end(),compare);

        int endtime = vec[0].second;
        int count =1;
        for(int i=1;i<n;i++){
            if(vec[i].first>=endtime){
                count ++;
                endtime = vec[i].second;
            }
        }
        cout << count;
        return 0;
    }