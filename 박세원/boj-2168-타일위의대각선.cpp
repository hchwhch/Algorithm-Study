#include <iostream>

using namespace std;

int x, y;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> x >> y;
    cout << x + y - gcd(x, y) << "\n";

    return 0;
}