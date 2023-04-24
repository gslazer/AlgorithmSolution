// neople1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}

vector<int> UnfoldVector(vector<vector <int>> foldedVector)
{
    vector<int> result;
    for (auto& i : foldedVector)
        for (int j = 0; j< i[1]; j++)
            result.push_back(i[0]);
    return result;
}

int solution(vector<vector <int>> goods, vector<vector<int>> coupons)
{
    long long answer = 0;
    /*qsort(&goods[0], goods.size(), sizeof(goods[0]), compare);
    qsort(&coupons[0], coupons.size(), sizeof(coupons[0]), compare);*/

    vector<int> unfoldedGoods = UnfoldVector(goods);
    vector<int> unfoldedCoupons = UnfoldVector(coupons);

    sort(unfoldedGoods.begin(), unfoldedGoods.end(), compare);
    sort(unfoldedCoupons.begin(), unfoldedCoupons.end(), compare);

    for (int i = 0; i < unfoldedGoods.size(); i++)
    {
        if (i >= unfoldedCoupons.size())
            answer += unfoldedGoods[i];
        else
            answer += ((long long)unfoldedGoods[i] * (100 - unfoldedCoupons[i]) / 100);
    }

    return answer;
}

int main()
{
    cout << solution({ {3100, 2},{7700, 1},{3100, 2} }, { {33, 4} });

    
    std::cout << "Hello World!\n";
}
