#include <iostream>
using namespace std;
int n, l, a[104][104], b[104][104], ret;
void solve(int a[104][104]) {
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        int j;
        for (j = 0; j < n - 1; j++) {
            if (a[i][j] == a[i][j + 1]) cnt++;
            else if (a[i][j] + 1 == a[i][j + 1] && cnt >= l) cnt = 1; //초기화
            else if (a[i][j] - 1 == a[i][j + 1] && cnt >= 0) cnt = -l + 1; //내리막길
            else break;
        }
        if (j == n - 1 && cnt >= 0) ret++; //길 있네!!
    }
    return;
   
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            b[j][i] = a[i][j]; //대칭 만들기
        }
    }
    solve(a);
    solve(b);
    cout << ret << '\n';
    return 0;
}

