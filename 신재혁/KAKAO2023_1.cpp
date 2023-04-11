#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;
int y, m, d, total;
map<char, int> t_map;
vector<int> priv;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    y = stoi(today.substr(0, 4));
    m = stoi(today.substr(5, 2));
    d = stoi(today.substr(8, 2));
    total = y * 12 * 28 + (m - 1) * 28 + d;

    for (int i = 0; i < terms.size(); i++) {
        //약관 자르기
        stringstream ss(terms[i]);
        char alpha;
        int month;
        ss >> alpha >> month;
        t_map[alpha] = month;
    }
    for (int i = 0; i < privacies.size(); i++) {
        //프라이버시 날짜 계산
        int year = stoi(privacies[i].substr(0, 4));
        int month = stoi(privacies[i].substr(5, 2));
        int day = stoi(privacies[i].substr(8, 2));
        char tmp = privacies[i].back();

        int temp = year * 12 * 28 + (month - 1) * 28 + day + (t_map[tmp] * 28 - 1);
        priv.push_back(temp);


    }
    for (int i = 0; i < priv.size(); i++) {

        if (priv[i] < total) {
            answer.push_back(i + 1);
        }
    }
    return answer;
}