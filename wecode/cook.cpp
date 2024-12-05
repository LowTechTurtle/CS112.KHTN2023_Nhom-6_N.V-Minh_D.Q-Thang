#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    vector<int> a, b;

    cin >> n >> m >> k;
    int f,g;
    for (int i = 0; i < n; i++)
        {
            cin>>f;
            a.push_back(f);
        }
    for (int i = 0; i < m; i++)
        {
            cin>>f;
            b.push_back(f);
        }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0, ans = 0;

    while (i < n && j < m) {
        if (abs(a[i] - b[j]) <= k) {
            ans++;
            i++;
            j++;
        } else if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }

    cout << ans << endl;
}
