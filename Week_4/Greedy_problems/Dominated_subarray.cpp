#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int start = -1, end = -1;
        int minLen = n + 1;

        for (int i = 1; i < n; i++) {
            auto it = find(a.begin(), a.begin() + i, a[i]);
            if (it != a.begin() + i) {
                start = it - a.begin();
                end = i;
                minLen = end - start + 1;
                break;
            }
        }

        if (end == -1) {
            cout << -1 << "\n";
            continue;
        }

        end++;
        for (; end < n; end++) {
            auto it = find(a.begin() + start + 1, a.begin() + end, a[end]);
            if (it != a.begin() + end) {
                start = it - a.begin();
                minLen = min(minLen, end - start + 1);
            }
        }

        cout << minLen << "\n";
    }
}
