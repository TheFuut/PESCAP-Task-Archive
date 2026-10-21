#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    int num_nodes = 2 * n;
    vector<vector<int>> adj(num_nodes);
    vector<vector<int>> radj(num_nodes);

    auto add_edge = [&](int u, int v) {
        adj[u].push_back(v);
        radj[v].push_back(u);
    };

    for (int i = 0; i < m; i++) {
        int t, a, b; cin >> t >> a >> b;

        int pos_a = 2 * (a - 1);
        int neg_a = 2 * (a - 1) + 1;
        int pos_b = 2 * (b - 1);
        int neg_b = 2 * (b - 1) + 1;

        if (t == 1) {
            add_edge(pos_a, pos_b);
            add_edge(neg_b, neg_a);
        } else if (t == 2) {
            add_edge(pos_a, neg_b);
            add_edge(pos_b, neg_a);
        } else if (t == 3) {
            add_edge(neg_a, pos_b);
            add_edge(neg_b, pos_a);
        }
    }

    vector<bool> visited(num_nodes, false);
    vector<int> order;
    order.reserve(num_nodes);

    auto dfs1 = [&](auto&& self, int u) -> void {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                self(self, v);
            }
        }
        order.push_back(u);
    };

    for (int i = 0; i < num_nodes; i++) {
        if (!visited[i]) {
            dfs1(dfs1, i);
        }
    }

    vector<int> comp(num_nodes, -1);
    int comp_id = 0;

    auto dfs2 = [&](auto&& self, int u, int c) -> void {
        comp[u] = c;
        for (int v : radj[u]) {
            if (comp[v] == -1) {
                self(self, v, c);
            }
        }
    };

    for (int i = num_nodes - 1; i >= 0; i--) {
        int u = order[i];
        if (comp[u] == -1) {
            dfs2(dfs2, u, comp_id++);
        }
    }

    for (int i = 0; i < n; i++) {
        if (comp[2 * i] == comp[2 * i + 1]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "SI\n";
    return 0;
}