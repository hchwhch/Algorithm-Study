#include <iostream>
using namespace std;
int n;
bool isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}
void dfs(int num, int len) {
    if (len == n) {
        cout << num << '\n';
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (isPrime(num * 10 + i)) {
            dfs(num * 10 + i, len + 1);
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    dfs(2, 1);
    dfs(3, 1);
    dfs(5, 1);
    dfs(7, 1);
}

