#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int> board[4][4];
int n;
const int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dead[17];
//물고기는 방향이 이동할 수 있는 칸을 향할때 까지 45도 회전/물고기는 서로의 위치를 자리 바꿈
void swap(int y, int x, int ny, int nx) {
    int tmpn = board[y][x].first; //물고기의 번호
    int tmpd = board[y][x].second; //물고기의 방향

    board[y][x].first = board[ny][nx].first;
    board[y][x].second = board[ny][nx].second;

    board[ny][nx].first = tmpn;
    board[ny][nx].second = tmpd;
}
int solve(int y, int x) {
    pair<int, int> tmp[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            tmp[i][j] = board[i][j];
        }
    }
    //상어가 먹는다
    int fishN = board[y][x].first;
    int dir = board[y][x].second;
    
    dead[fishN] = 1;
    board[y][x].first = -1;

    //물고기 이동
    for (int i = 1; i <= 16; i++) {
        bool find = false;
        if (dead[i]) continue;
        
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (board[j][k].first == i) {
                    for (int t = 0; t < 8; t++) {
                        int ndir = board[j][k].second + t;
                        int ny = j + dy[ndir % 8];
                        int nx = k + dx[ndir % 8];

                        if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) continue;
                        if (ny == y && nx == x) continue;
                        board[j][k].second = ndir;
                        swap(j, k, ny, nx);
                        find = true;
                        break;
                    }
                }
                if (find) break;
            }
            if (find) break;
        }

    }
    int ret = fishN;

    for (int i = 1; i <= 3; i++) {
        //상어가 먹을 수 있는 물고기 번호 합의 최댓값
        int ny = y + dy[dir % 8] * i;
        int nx = x + dx[dir % 8] * i;

        if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) continue;
        if (board[ny][nx].first == -1) continue;

        ret = max(ret, solve(ny, nx) + fishN);
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = tmp[i][j];
        }
    }
    dead[fishN] = 0;
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int a, b;
            cin >> a >> b;
            board[i][j] = { a, b - 1 };
        }
    }
    cout << solve(0, 0) << '\n';
    return 0;
}

