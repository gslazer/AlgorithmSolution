// neople4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int n;

int main()
{
	cin >> n;

	int answer = 2;
	int num = 2;
	int index = 1;

	while (1) {
		for (int i = num/2 ; i >=2 ; i--)
		{
			if (num % i != 0)
			{
				continue;
			}
			int temp = num;
			bool flag = false;
			for (int j = i; j >= num / i; j--)
			{
				if (temp % j != 0)
					break;
				temp /= j;
				if (temp == 1)
				{
				
					flag = true;
					break;
				}
			}
			if (flag)
			{
				index++;
				break;
			}
		}
		if (index == n)
			break;
		num++;
	}
	cout << num;
	return 0;
}