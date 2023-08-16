#include <iostream>
using namespace std;
char board[22][22];
int n, m, coin_y1, coin_x1, coin_y2, coin_x2;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int solve(int y1, int x1, int y2, int x2, int cnt) {
    if (cnt >= 11) return -1;
    bool is_out1 = false, is_out2 = false;

    if (y1 < 0 || y1 >= n || x1 < 0 || x1 >= m) is_out1 = true;
    if (y2 < 0 || y2 >= n || x2 < 0 || x2 >= m) is_out2 = true;

    if (is_out1 && is_out2) return -1; //두 동전이 다 떨어질 경우
    if (is_out1 || is_out2) return cnt;

    int ret = -1;
    for (int i = 0; i < 4; i++) {
        int ny1 = y1 + dy[i];
        int nx1 = x1 + dx[i];
        int ny2 = y2 + dy[i];
        int nx2 = x2 + dx[i];

        if (board[ny1][nx1] == '#') { //벽일 경우 이동하지 않는다.
            ny1 = y1;
            nx1 = x1;
        }
        if (board[ny2][nx2] == '#') {
            ny2 = y2;
            nx2 = x2;
        }
        int tmp = solve(ny1, nx1, ny2, nx2, cnt + 1);
        if (tmp == -1) continue;
        if (ret == -1 || ret > tmp) {
            ret = tmp;
        }
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    coin_y1 = coin_x1 = coin_y2 = coin_x2 = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'o') {
                if (coin_y1 == -1) {
                    coin_y1 = i;
                    coin_x1 = j;
                }
                else {
                    coin_y2 = i;
                    coin_x2 = j;
                }
                board[i][j] = '.';
            }
        }
    }
    cout << solve(coin_y1, coin_x1, coin_y2, coin_x2, 0) << '\n';
    return 0;
}

