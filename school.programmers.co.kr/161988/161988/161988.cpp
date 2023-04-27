#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long GetMaxSum(vector<int> vec)
{
    long long maxSum = 0, curSum = 0;

    for (int i = 0; i < vec.size(); i++)
    {
        if (curSum + vec[i] > 0)
            curSum += vec[i];
        else
            curSum = 0;
        if (maxSum < curSum)
            maxSum = curSum;
    }
    return maxSum;
}

long long solution(vector<int> sequence) 
{
    long long answer = 0;
    vector<int> sequence1;
    vector<int> sequence2;

    for (int i = 0; i < sequence.size(); i++)
    {
        sequence1.push_back(sequence[i] * ( 1 +  i%2 * -2)) ;
        sequence2.push_back(sequence[i] * ( 1 + (i+1) % 2 * -2));
    }
    long long sum1 = GetMaxSum(sequence1);
    long long sum2 = GetMaxSum(sequence2);

    return sum1>sum2? sum1 : sum2;
}

int main()
{
    cout << solution({ 2, 3, -6, 1, 3, -1, 2, 4 });
}