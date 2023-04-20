#include <iostream>
#include <map>
#include <queue>

using namespace std;
int N, M;
map<int, queue<int>> permitionMap;
map<int, map<int, bool>> folowerMap;
map<int, int> folowers;

void calculateFolowers(int a)
{

	if (folowers[a] != 0)
	{
		return;
	}

	int folowerCount = 0;

	folowerMap[a][a] = true;

	if (permitionMap[a].size() == 0)
	{
		folowerCount = folowers[a] = 1;
		return;
	}

	for(int permitionNod = permitionMap[a].front(); permitionMap[a].size() > 0; permitionMap[a].pop())
	{
		if (folowerMap[a][permitionNod])
		{
			continue;
		}

		folowerMap[a][permitionNod] = true;
		folowerCount++;
		calculateFolowers(permitionNod);

		for (const auto& childNod : folowerMap[permitionNod])
		{
			if (folowerMap[a][childNod.first])
				continue;
			folowerMap[a][childNod.first] = true;
			folowerCount++;
		}
	}

	folowers[a] = folowerCount;

	return;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		permitionMap[b].push(a);
	}

	int maxFolowers = 0;
	for (int i = 1; i <= N; i++)
	{
		if (folowers[i] == 0)
			calculateFolowers(i);
		if (folowers[i] > maxFolowers)
			maxFolowers = folowers[i];
	}
	for (int i = 1; i <= N; i++)
	{
		if (folowers[i] == maxFolowers)
		{
			cout << i << " ";
		}
	}
}