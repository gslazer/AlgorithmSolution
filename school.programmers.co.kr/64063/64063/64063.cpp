// 64063.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number)
{
    vector<long long> answer;

    map<long long, bool>checked_room;

    for (long long i = 0; i < room_number.size(); i++)
    {
        if (!checked_room[room_number[i]])
        {
            checked_room[room_number[i]] = true;
            answer.push_back(room_number[i]);
        }
        else
        {
            long long j = room_number[i];
            while (checked_room[j] == true)
                j++;
            checked_room[j] = true;
            answer.push_back(j);
        }
    }
    return answer;
}
int main()
{
    std::cout << "Hello World!\n";
}
