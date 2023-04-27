#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//bool cmp(vector<int>& v1, vector<int>& v2) {
//
//    return v1[0] + v1[1] > v2[0] + v2[1];
//}

int solution(vector<vector<int>> scores) {

    vector<int> ownerScore = { scores[0][0],scores[0][1] };

    sort(scores.begin(), scores.end(), [](vector<int>& v1, vector<int>& v2) {
            return v1[0] + v1[1] > v2[0] + v2[1];
        });
    
    int currentRank = 0;
    int currentScore = 200001;

    for (int i = 0; i < scores.size(); i++)
    {
        scores.erase(remove_if(scores.begin()+i, scores.end(), [s = scores[i]](vector<int>& v) {
                return v[0] < s[0] && v[1] < s[1]; 
            }), scores.end());
        if (currentScore > scores[i][0]+ scores[i][1])
        {
            currentRank = i + 1;
            currentScore = scores[i][0] + scores[i][1];
        }
        if (scores[i][0] == ownerScore[0] && scores[i][1] == ownerScore[1])
        {
            return currentRank;
        }
    }

    return -1;
}

int main()
{
    cout << solution({ {2, 2}, {1, 4}, {3, 2}, {3, 2}, {2, 1} });
}