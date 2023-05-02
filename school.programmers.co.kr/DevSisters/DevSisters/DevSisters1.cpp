#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> quest) {
    sort(quest.begin(), quest.end(), [](vector<int>l, vector<int>r){
            return l[0]<r[0];
        });
    int currentExp = 0;
    int result = 0;
    for (auto& currentQuest : quest)
    {
        if (currentExp < currentQuest[0])
            break;
        currentExp += currentQuest[1];
        result++;
    }

    return result;
}

int main()
{
    cout << solution({ {7,4},{2,4},{13,5},{0,3},{14,10}});
}
