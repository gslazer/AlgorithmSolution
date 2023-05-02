#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> field, int farmSize) {
    int answer = -1;

    for (int i = 0; i <= field.size() - farmSize; i++)
    {
        for (int j = 0; j <= field[0].size() - farmSize; j++)
        {
            bool flag = true;
            int stonCount = 0;
            for (int k = i; k < i + farmSize; k++)
            {
                for (int l = j; l < j + farmSize; l++)
                {
                    if (field[k][l] == 2)
                    {
                        flag = false;
                        break;
                    }
                    if (field[k][l] == 1)
                    {
                        stonCount++;
                    }
                }
                if (!flag)
                    break;
            }
            if (flag)
            {
                if (answer == -1 || answer > stonCount)
                    answer = stonCount;
            }
        }
    }

    return answer;
}
int main()
{
    cout << solution({ {0,0,1,0,0}, {1,1,0,0,2}, {1,0,0,0,0} }, 3);
}
