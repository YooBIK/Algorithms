#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    int visit[100][100];
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            visit[i][j] = -1;
        }
    }
    int dir_row[4] = {0,0,1,-1};
    int dir_col[4] = {1,-1,0,0};

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visit[i][j]==-1 && picture[i][j] != 0){
                int area = 0;
                queue<pair<int,int>> q;
                q.push({i,j});
                int curArea = 1;
                visit[i][j] = picture[i][j];
                while(!q.empty()){
                    int cur_row = q.front().first;
                    int cur_col = q.front().second;
                    q.pop();
                    for(int i=0;i<4;i++){
                        int new_row = cur_row + dir_row[i];
                        int new_col = cur_col + dir_col[i];
                        if(new_row >= 0 && new_row < m && new_col >= 0 && new_col < n && visit[new_row][new_col] == -1 && picture[new_row][new_col] == picture[cur_row][cur_col]){
                            q.push({new_row,new_col});
                            curArea++;
                            visit[new_row][new_col] = picture[new_row][new_col];
                        }
                    }
                }
                max_size_of_one_area = max(curArea,max_size_of_one_area);
                number_of_area++;
            }

        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}