#include <iostream>
using namespace std;

int N;
int answerAfter0[100001];
int answerAfterN[100001];
int solutionAfterN(int n);

int solutionAfter0(int n)
{
    int result;
    if (answerAfter0[n] != 0)
        return answerAfter0[n];

    if (answerAfterN[n - 1] == 0)
        solutionAfterN(n - 1);

    result = answerAfter0[n - 1] + (answerAfterN[n - 1] * 2);
    if (result > 9901)
        result = result % 9901;
    answerAfter0[n] = result;
    return result;
}

int solutionAfterN(int n)
{
    int result = 0;
    if (answerAfterN[n] != 0)
        return answerAfterN[n];
    result += answerAfter0[n - 1] + answerAfterN[n - 1];

    if (result > 9901)
        result = result % 9901;

    answerAfterN[n] = result;
    return result;
}

int main()
{
    answerAfter0[1] = 3;
    answerAfterN[1] = 2;
    answerAfterN[1] = 2;

    cin >> N;
    for (int index = 1; index <= N; index++)
    {
        solutionAfter0(index);
    }
    cout << answerAfter0[N];
    return 0;
}