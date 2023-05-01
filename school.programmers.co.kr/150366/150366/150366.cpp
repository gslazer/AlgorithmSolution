#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> parseString(const string& input) {
    vector<std::string> result;
    /*stringstream ss(input);
    string token;
    while (std::getline(ss, token, ' ')) {
        result.push_back(token);
    }*/
    return result;
}

vector<string> solution(vector<string> commands) {

    vector<string*>temp;
    for (const string& command : commands)
    {
        const auto& parsedString = parseString(command);
    }

    vector<string> answer ;

    return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}