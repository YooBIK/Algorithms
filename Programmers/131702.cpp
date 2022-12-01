#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dir_row[4] = {0, 0, 1, -1};
int dir_col[4] = {1, -1, 0, 0};

bool checker(vector<vector<int>> &map)
{
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map.size(); j++)
        {
            if (map[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool checkEWSN(vector<vector<int>> &map, int row, int col)
{
    if (map[row][col] == 0)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dir_row[i];
            int newCol = col + dir_col[i];
            if (newRow >= 0 && newRow < map.size() && newCol >= 0 && newCol < map.size())
            {
                if (map[newRow][newCol] == 0)
                {
                    return false;
                }
            }
            else
            {
                continue;
            }
        }
        return true;
    }
}

void changeMap(vector<vector<int>> &map, int row, int col)
{
    map[row][col] = (map[row][col] + 1) % 4;
    for (int i = 0; i < 4; i++)
    {
        int newRow = row + dir_row[i];
        int newCol = col + dir_col[i];
        if (newRow >= 0 && newRow < map.size() && newCol >= 0 && newCol < map.size())
        {
            map[newRow][newCol] = (map[newRow][newCol] + 1) % 4;
        }
        else
        {
            continue;
        }
    }
}

int solution(vector<vector<int>> clockHands)
{
    int answer = 0;
    int row = clockHands.size();
    int col = clockHands.size();

    
    for (int i = 0; i < clockHands.size(); i++)
    {
        bool flag = true;
        for (int j = 0; j < clockHands.size(); j++)
        {
            bool flag = true;
            if (checkEWSN(clockHands, i, j))
            {
                answer++;
                changeMap(clockHands, i, j);
            }
            else
            {
                continue;
            }
        }
    }
    return answer;
}