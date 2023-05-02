#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

constexpr double BallDiameter = 2;

int solution(vector<vector<double>> objectBallPosList, vector<double> hitVector) {

    //기울기가 inclination = hitVector[1] / hitVecotr[0] 인 직선과 좌표 사이의 거리가 BallDiameter 보다 작을 경우 충돌로 판정한다.
    //기울기가 inclination 인 직선의 공식은 y = inclination * x 
    //ax + by + c = 0 형태로 고쳤을때 a = inclination, b = -1
    
    //점(x1, y1)과 직선 사이의 거리 k =  abs(ax1 + by1 + c) / sqrt(a^2 + b^2)
    
    // a = inclination, b = -1 을 대입하면
    // k = abs(inclination * x1 - y1) / sqrt(inclination^2 + 1)

    double inclination;
    double crossPosX = -1.0;
    int answer = -1;
    double minDistanceFrom0 = -1;

    if (hitVector[0] != 0)
        inclination =  hitVector[1] / hitVector[0]; // hitVector[0] 이 0인 경우의 예외처리 필요!!!
    else
    {
        for (int i = 0; i < objectBallPosList.size(); i++)
        {
            double distance = objectBallPosList[i][0];
            if (answer == -1 || minDistanceFrom0 > distance)
            {
                answer = i;
                minDistanceFrom0 = distance;
            }
        }
        return answer;
    }


    for (int i = 0; i<objectBallPosList.size(); i++)
    {
        double distance = abs(inclination * objectBallPosList[i][0] - objectBallPosList[i][1]) / sqrt(inclination * inclination + 1.0);
        if (distance >= BallDiameter)
        {
            continue;
        }
        double distanceFrom0 = sqrt(pow(objectBallPosList[i][0], 2) + pow(objectBallPosList[i][1], 2));
        if (answer == -1 || minDistanceFrom0 > distanceFrom0)
        {
            answer = i;
            minDistanceFrom0 = distanceFrom0;
        }
    }

    return answer;
}

int main()
{
    std::cout << solution({ {5.0, 0.0}, {0.0, 3.0}}, { 1.0, 1.0 });
}