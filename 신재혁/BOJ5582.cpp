#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string str1, str2;
int lcs[4001][4001];
int ret = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str1 >> str2;
    lcs[0][0] = 0;

    for (int i = 0; i < str1.size(); i++) {
        for (int j = 0; j < str2.size(); j++) {
            if (str1[i] == str2[j]) {
                if (i == 0 || j == 0) {
                    lcs[i][j] = 1;
                }
                else {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                }
                ret = max(ret, lcs[i][j]);
            }
        }
    }
    cout << ret;
    

    return 0;
}

