#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int dx[] = {-2, -1, -1, -1, 0, 0, 0, 0, 0, 1, 1, 1, 2};
int dy[] = {0, -1, 0, 1, -2, -1, 0, 1, 2, -1, 0, 1, 0};

int m, n;
int a[N][N], ans[N][N], delta[N][N];

void input() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
}

bool update(int x, int y, int val) {
    bool isval = true;
    for (int i = 0; i < 13; i++) {
        int u = x + dx[i], v = y + dy[i];
        if (u >= 1 && u <= m && v >= 1 && v <= n) {
            delta[u][v] += val;
            if (delta[u][v] > a[u][v] || delta[u][v] < 0)
                isval = false;
        }
    }
    return isval;
}

bool cval(int i, int j) {
    if (i - 2 >= 1 && delta[i - 2][j] != 0)
        return false;
    if (i - 1 >= 1) {
        if (j - 1 >= 1 && delta[i - 1][j - 1] > 1)
            return false;
        if (delta[i - 1][j] > 2 - (j == n))
            return false;
    }
    return true;
}

void backtrack(int i, int j) {
    if (i == m + 1) {
        for (int x = m - 1; x <= m; x++)
            for (int y = 1; y <= n; y++)
                if (delta[x][y] != a[x][y]) return;

        for (int x = 1; x <= m; x++) {
            for (int y = 1; y <= n; y++)
                cout << ans[x][y] << ' ';
            cout << '\n';
        }
        exit(0);
    }

    int nxt_i = i, nxt_j = j + 1;
    if (nxt_j == n + 1) {
        nxt_j = 1;
        nxt_i++;
    }

    if (update(i, j, 1)) {
        ans[i][j] = 1;
        if (cval(i, j))
            backtrack(nxt_i, nxt_j);
    }
    update(i, j, -1);
    ans[i][j] = 0;

    if (cval(i, j))
        backtrack(nxt_i, nxt_j);
}

void solve() {
    memset(delta, 0, sizeof(delta));
    backtrack(1, 1);
}

int main() {
    input();
    solve();

    return 0;
}
