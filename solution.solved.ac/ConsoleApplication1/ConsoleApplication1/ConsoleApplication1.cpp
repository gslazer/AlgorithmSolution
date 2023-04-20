#include <iostream>
#include <math.h>
using namespace std;

int N, R, C;
int length;

int nCount(int length, int r, int c)
{
    if (r < 2 && c < 2)
    {
        return r * 2 + c;
    }
    int halfLength = length / 2;
    int result = 0;
    int halfSware = halfLength * halfLength;
    
    if (halfLength <= c && halfLength <= r)
    {
        result += halfSware * 3;
        result += nCount(halfLength, r - halfLength, c - halfLength);
    }
    else if (halfLength <= r)
    {
        result += halfSware * 2;
        result += nCount(halfLength, r - halfLength, c);
    }
    else if (halfLength <= c)
    {
        result += halfSware;
        result += nCount(halfLength, r, c - halfLength);
    }
    else
    {
        result += nCount(halfLength, r, c);
    }
    return result;
}

int main()
{
    cin >> N >> R >> C;
    length = pow(2, N);
    cout << nCount(length, R, C);
}