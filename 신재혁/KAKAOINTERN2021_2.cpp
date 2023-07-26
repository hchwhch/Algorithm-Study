#include <string>
#include <vector>
#include <iostream>
using namespace std;
const int dy1[] = { -1, 0, 1, 0 };
const int dx1[] = { 0, 1, 0, -1 }; //상하좌우
const int dy2[] = { -1, -1, 1, 1 };
const int dx2[] = { -1, 1, -1, 1 }; //대각선
int chk(vector<string>& board) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] != 'P') continue;

            //상하좌우로 거리가 1인 응시자 확인
            for (int dir = 0; dir < 4; dir++) {
                int ny = i + dy1[dir];
                int nx = j + dx1[dir];

                if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
                if (board[ny][nx] == 'P') return 0;
            }

            //대각선에 위치한 응시자 확인
            for (int dir = 0; dir < 4; dir++) {
                int ny = i + dy2[dir];
                int nx = j + dx2[dir];

                if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
                //대각선에 응시자가 있을 경우 파티션 존재 여부 확인
                if (board[ny][nx] == 'P') {
                    if (board[i][nx] != 'X' || board[ny][j] != 'X') return 0;
                }
            }
            //상하좌우로 거리가 2인 응시자 확인
            for (int dir = 0; dir < 4; dir++) {
                int ny = i + 2 * dy1[dir];
                int nx = j + 2 * dx1[dir];

                //거리가 2인 곳에 응시자가 있을 경우 파티션 존재 확인
                if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
                if (board[ny][nx] == 'P') {
                    if (board[i + dy1[dir]][j + dx1[dir]] != 'X') return 0;
                }
            }
        }
    }
    return 1;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (auto& p : places) answer.push_back(chk(p));
    return answer;
}