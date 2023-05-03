#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
map<char, int> score;
string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int n = survey.size();

    for (int i = 0; i < n; i++) {
        if (choices[i] <= 3) {
            //매우 비동의, 비동의, 약간 비동의일 경우
            score[survey[i][0]] += 4 - choices[i];
        }
        else score[survey[i][1]] += choices[i] - 4;
    }

    if (score['R'] >= score['T']) answer += 'R';
    else answer += 'T';

    if (score['C'] >= score['F']) answer += 'C';
    else answer += 'F';

    if (score['J'] >= score['M']) answer += 'J';
    else answer += 'M';

    if (score['A'] >= score['N']) answer += 'A';
    else answer += 'N';

    return answer;
}