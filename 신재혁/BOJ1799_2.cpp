#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, board[10][10];
bool isUsed1[20]; //우상향
bool isUsed2[20]; //좌상향
int ans = 0;
void bishop(int th, int size) {
    //th는 우상향 대각선의 index, size는 이전에 선택한 비숍의 개수
    if (th >= 2 * n - 1) {
        ans = max(ans, size);
    }
    else {
        bool flag = false; //th번째 대각선에서 비숍을 놓았는지를 나타내는 flag

        for (int j = 0; j < n - abs(th - (n - 1)); j++) {
            int y = (n - 1 <= th) ? n - 1 - j : th - j;
            int x = (n - 1 <= th) ? th - (n - 1) + j: j;

            //비숍을 놓을 수 있으면서, 우상향 대각선과 좌상향 대각선에 비숍이 없는 경우
            if (board[y][x] == 1 && !isUsed1[th] && !isUsed2[n - 1 + (y - x)]) {
                flag = true;
                isUsed1[th] = true;
                isUsed2[n - 1 + (y - x)] = true;
                bishop(th + 1, size + 1);
                isUsed1[th] = false;
                isUsed2[n - 1 + (y - x)] = false;
            }
        }
        if (!flag) bishop(th + 1, size); //th번째 대각선에서 비숍을 놓지 않을 경우, size를 놓지 않고, th+1번째 비숍 선택
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    bishop(0, 0);
    cout << ans << '\n';
    return 0;
}
