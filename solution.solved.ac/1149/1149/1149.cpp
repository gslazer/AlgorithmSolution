#include <iostream>
using namespace std;
int N;
int R, G, B;

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int r, g, b;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> r >> g >> b;
        int newR = r + min(G, B);
        int newG = g + min(R, B);
        int newB = b + min(R, G);
        R = newR;
        G = newG;
        B = newB;
    }
    cout << min(R, min(G, B));
}
