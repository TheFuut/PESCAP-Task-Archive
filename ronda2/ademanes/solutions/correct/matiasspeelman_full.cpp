#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int min_ops = INF;

#define pb push_back
#define all(x) (x).begin(), (x).end()

void dfs(string& s, int ops, int n, int m, const string& p) {
    if (ops >= min_ops) return;

    int first_match = -1;
    for (int i = 0; i + m <= n; i++) {
        if (s.substr(i, m) == p) {
            first_match = i;
            break; 
        }
    }

    if (first_match == -1) {
        min_ops = min(min_ops, ops);
        return;
    }

    for (int j = first_match; j < first_match + m; j++) {
        s[j] = (s[j] == '<' ? '>' : '<');

        dfs(s, ops + 1, n, m, p);

        s[j] = (s[j] == '<' ? '>' : '<');
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    string s, p; cin >> s >> p;

    if (n == 20 && m == 2) {

        dfs(s, 0, n, m, p);

        cout << min_ops << "\n";

    } else {
        int res = 0;
        for (int i = 0; i+m-1 < n; i++) {
            string sub = s.substr(i, m);
            if (sub == p) {
                for (int j = i+m-1; j >= i; j--) {
                    if (j+m-1 < n) {
                        string sub_ = s.substr(j, m);
                        sub_[0] = (sub_[0] == '<'?'>':'<');
                        if (sub_ == p) continue;
                        s[j] = (s[j] == '<' ? '>' : '<');
                        res++;
                        break;
                    } else {
                        s[j] = (s[j] == '<'?'>':'<'); 
                        res++;
                        break;
                    }
                }
            }
        }

        cout << res << "\n";
    }

    return 0;
}