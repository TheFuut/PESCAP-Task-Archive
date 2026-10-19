#include <math.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#include <set>
#include <map>
#include <list>
#include <tuple>
#include <ranges>
#include <vector>
#include <bitset>
#include <algorithm>
#include <functional>

using namespace std;
#define uint unsigned long long
#define int long long

// #define TEST_CASES
// #define DEBUG

template<class T>
using triplet = tuple<T, T, T>;

class DSU {
public:
  DSU(uint n): parent(n), size(n, 1) {
    for (uint x = 0; x < n; x++)
      parent[x] = x;
  }

  uint find(uint a) {
    return parent[a] = (a == parent[a]) ? a : find(parent[a]);
  }

  void join(uint a, uint b) {
    a = find(a), b = find(b);
    if (size[a] < size[b])
      swap(a, b);
    parent[b] = a;
    size[a] += size[b];
  }

private:
  vector<uint> parent, size;
};

signed main() {
#ifdef TEST_CASES
  uint TTT;
  scanf("%llu", &TTT);
  while (TTT--) {
#endif

  // Solution starts here

  uint N, M, Q;
  scanf("%llu%llu%llu", &N, &M, &Q);

  vector<vector<pair<uint, uint>>> adj(N);
  set<triplet<uint>> e;
  for (uint x = 0; x < M; x++) {
    uint a, b, w;
    scanf("%llu%llu%llu", &a, &b, &w);
    a--, b--;

    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
    e.insert({w, a, b});
  }

  DSU dsu(N);

  vector<vector<pair<uint, uint>>> A(N);
  for (auto [w, a, b]: e) {
    if (dsu.find(a) != dsu.find(b)) {
      dsu.join(a, b);
      A[a].push_back({b, w});
      A[b].push_back({a, w});
    }
  }

  uint D[N];
  pair<uint, uint> P[N], LCA[N][32];
  function<void(uint, pair<uint, uint>*, uint)> lca_b = [&](uint n, pair<uint, uint>* p, uint d) {
    D[n] = d;
    if (d > 0) {
      // LCA[n][0] = p[d];
      // for (uint i = 1; i <= log2(d); i++) {
      //   auto bf = LCA[n][i - 1];
      //   LCA[n][i] = {LCA[bf.first][i - 1].first, max(LCA[bf.first][i - 1].second, bf.second)};
      // }
      for (uint i = 0; i <= log2(d); i++) {
        LCA[n][i] = p[d - (1 << i)];
      }
    }

    for (auto [c, w]: A[n]) {
      if (p[d].first == c) continue;
      p[d + 1] = {n, max(w, p[d].second)};
      lca_b(c, p, d + 1);
    }
  };

  P[0] = {0, 0};
  lca_b(0, P, 0);

  function<uint(uint, uint)> lca = [&](uint a, uint b) -> uint {
    if (D[a] > D[b]) swap(a, b);
    uint ans = 0;
    while (D[b] > D[a]) {
      uint d = log2(D[b] - D[a]);
      ans = max(ans, LCA[b][d].second);
      b = LCA[b][d].first;
    }

    while (b != a) {
    uint l = 0, r = log2(D[a]);
      while (l < r) {
        uint mid = l + (r - l) / 2;
        if (LCA[a][mid].first != LCA[b][mid].first)
          l = mid + 1;
        else r = mid;
      }

      ans = max(ans, max(LCA[a][l].second, LCA[b][l].second));
      a = LCA[a][l].first;
      b = LCA[b][l].first;
    }

    return ans;
  };

  while (Q--) {
    uint a, b;
    scanf("%llu%llu", &a, &b);
    a--, b--;
    printf("%llu\n", lca(a, b));
  }

  // Solution ends here

#ifdef TEST_CASES
  }
#endif
}