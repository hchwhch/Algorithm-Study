#include <iostream>
#include <vector>
using namespace std;
int board[9][9];
vector<pair<int, int>> points; //빈칸의 위치 저장
int cnt = 0;
bool found = false;
bool check(pair<int, int> p) {
    int square_x = p.first / 3;
    int square_y = p.second / 3;

    for (int i = 0; i < 9; i++) {
        if (board[p.first][i] == board[p.first][p.second] && i != p.second) {
            //같은 행에 같은 숫자가 위치할 경우
            return false;
        }
        if (board[i][p.second] == board[p.first][p.second] && i != p.first) {
            //같은 열에 같은 숫자가 위치할 경우
            return false;
        }
    }

    for (int i = 3 * square_x; i < 3 * square_x + 3; i++) {
        for (int j = 3 * square_y; j < 3 * square_y + 3; j++) {
            //나눈 구역 확인
            if (board[i][j] == board[p.first][p.second]) {
                if (i != p.first && j != p.second) {
                    return false;
                }
            }
        }
    }
    return true;
}
void func(int n) {
    if (n == cnt) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        found = true;
        return;
    }

    for (int i = 1; i <= 9; i++) {
        board[points[n].first][points[n].second] = i; //1~9까지의 숫자 넣음
        if (check(points[n])) {
            func(n + 1);
        }
        if (found) return;
    }
    board[points[n].first][points[n].second] = 0; //값 비워주기
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pair<int, int> point;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                cnt++;
                point.first = i;
                point.second = j;
                points.push_back(point);
            }
        }
    }
    func(0);
}

