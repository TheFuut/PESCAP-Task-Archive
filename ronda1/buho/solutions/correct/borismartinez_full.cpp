#include <math.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

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
#define uint unsigned int
// #define int long long

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
    if (parent[parent[a]] == parent[a])
      return parent[a];
    return parent[a] = find(parent[a]);
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

static const uint maxN = 200015;
static uint D[maxN];
static pair<uint, uint> LCA[maxN][20];
vector<vector<pair<uint, uint>>> mst;

static void b_lca(const uint n) {
  if (D[n] > 0) {
    const uint d = log2(D[n]);
    for (uint i = 1; i <= d; i++) {
      auto bf = LCA[n][i - 1];
      LCA[n][i] = {LCA[bf.first][i - 1].first, max(LCA[bf.first][i - 1].second, bf.second)};
    }
  }

  for (auto& [c, w]: mst[n]) {
    if (c == LCA[n][0].first)
      continue;
    LCA[c][0] = {n, w};
    D[c] = D[n] + 1;
    b_lca(c);
  }
}

signed main() {
#ifdef TEST_CASES
  uint TTT;
  scanf("%llu", &TTT);
  while (TTT--) {
#endif

  // Solution starts here

  uint N, M, Q;
  scanf("%u%u%u", &N, &M, &Q);

  {
    triplet<uint> q[M];
    for (uint x = 0; x < M; x++) {
      uint u, v, w;
      scanf("%u%u%u", &u, &v, &w);
      u--, v--;
      q[x] = {w, u, v};
    }

    sort(q, q + M);
    DSU dsu(N);
    mst.resize(N);

    for (auto& [w, u, v]: q) {
      if (dsu.find(u) != dsu.find(v)) {
        dsu.join(u, v);
        mst[u].push_back({v, w});
        mst[v].push_back({u, w});
      }
    }
  }

  D[0] = 0;
  LCA[0][0] = {0, 0};
  b_lca(0);

  while (Q--) {
    uint a, b;
    scanf("%u%u", &a, &b);
    a--, b--;
    if (D[a] > D[b]) swap(a, b);

    uint ans = 0;
    while (D[b] > D[a]) {
      uint d = log2(D[b] - D[a]);
      ans = max(ans, LCA[b][d].second);
      b = LCA[b][d].first;
    }

    if (D[b] == 0) {
      printf("%u\n", ans);
      continue;
    }

    uint d = log2(D[b]);
    for (int i = d; i >= 0; i--) {
      if (LCA[a][i].first == LCA[b][i].first) continue;
      ans = max(ans, max(LCA[a][i].second, LCA[b][i].second));
      a = LCA[a][i].first;
      b = LCA[b][i].first;
    }

    if (a != b)
      ans = max(ans, max(LCA[a][0].second, LCA[b][0].second));

    printf("%u\n", ans);
  }

  // Solution ends here

#ifdef TEST_CASES
  }
#endif
}