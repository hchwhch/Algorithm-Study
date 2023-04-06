#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, q;
int board[64][64], tmp[64][64];
int visited[64][64];
bool checkmelt[64][64];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int dfs(int y, int x) {
    //connected components 
    visited[y][x] = 1;
    int ret = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (board[ny][nx] > 0 && !visited[ny][nx]) {
            ret += dfs(ny, nx);
        }
    }
    return ret;
}
//가장 큰 덩어리 찾기
int getBiggest() {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] > 0 && !visited[i][j]) {
                ret = max(ret, dfs(i, j));
            }
        }
    }
    return ret;
}
//얼음의 합 반환
int iceSum() {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ret += board[i][j];
        }
    }
    return ret;
}
//격자 시계방향 회전
void rotate(int y, int x, int L) {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            tmp[i][j] = board[y + L - 1 - j][x + i];
        }
    }
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            board[y + i][x + j] = tmp[i][j];
        }
    }
}
void solve(int L) {
    L = (1 << L);

    for (int i = 0; i < n; i += L) {
        for (int j = 0; j < n; j += L) {
            rotate(i, j, L);
        }
    }

    //얼음 융해
    memset(checkmelt, false, sizeof(checkmelt));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) continue;
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                if (board[ny][nx] > 0) cnt++; //얼음이 있는 칸 게산
            }
            if (cnt < 3) checkmelt[i][j] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (checkmelt[i][j]) board[i][j]--;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> q;
    n = (1 << n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    while (q--) {
        int L;
        cin >> L;
        solve(L);
    }

    cout << iceSum() << '\n';
    cout << getBiggest() << '\n';
    return 0;
}

