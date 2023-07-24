#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string s) {
    string arr[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    for (int i = 0; i < 10; i++) {
        while (true) {
            auto pos = s.find(arr[i]);
            if (pos == string::npos) break;
            s.replace(pos, arr[i].size(), to_string(i));
        }
    }
    return stoi(s);
}