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

signed main() {
#ifdef TEST_CASES
  uint TTT;
  scanf("%llu", &TTT);
  while (TTT--) {
#endif

  // Solution starts here

  int N;
  scanf("%llu", &N);
  int mat[1005][1005];

  auto make_xy = [&](int y, int x) -> int {
    return y * N + x;
  };

  auto unmake_xy = [&](int dat) -> pair<int, int> {
    return {dat / N, dat % N};
  };

  map<int, int> value;
  set<pair<int, int>, greater<pair<int, int>>> q;

  for (int y = 0; y < N; y++)
    for (int x = 0; x < N; x++)
      scanf("%llu", &mat[y][x]);

  auto query = [&](int y, int x) {
    int ans = 0;
    for (auto [dy, dx]: (vector<pair<int, int>>){
      {-1,  0},
      { 1,  0},
      { 0, -1},
      { 0,  1},
      { 0,  0}
    }) {
        if (dy + 1 + y == 0 || dx + 1 + x == 0 || dy + y == N || dx + x == N) continue;
        ans += mat[y + dy][x + dx];
    }

    return ans;
  };

  auto rem = [&](int y, int x) {
    for (auto [dy, dx]: (vector<pair<int, int>>){
      {-1,  0},
      { 1,  0},
      { 0, -1},
      { 0,  1},
      { 0,  0}
    }) {
        if (dy + 1 + y == 0 || dx + 1 + x == 0 || dy + y == N || dx + x == N) continue;
        int sy = y + dy;
        int sx = x + dx;

        mat[sy][sx] = 0;
        if (!(sy == y && sx == x)) {
          auto it = q.find({value[make_xy(sy, sx)], make_xy(sy, sx)});
          if (it != q.end())
            q.erase(it);
        }
    }

    for (auto [dy, dx]: (vector<pair<int, int>>){
      {-1,  0},
      { 1,  0},
      { 0, -1},
      { 0,  1},
    }) {
      if (dy + 1 + y == 0 || dx + 1 + x == 0 || dy + y == N || dx + x == N) continue;
      int sy = y + dy;
      int sx = x + dx;

      for (auto [dy, dx]: (vector<pair<int, int>>){
        {-1,  0},
        { 1,  0},
        { 0, -1},
        { 0,  1},
      }) {
        if (dy + 1 + sy == 0 || dx + 1 + sx == 0 || dy + sy == N || dx + sx == N || (y == (sy + dy) && x == (sx + dx))) continue;
        int id = make_xy(sy + dy, sx + dx);
        if (q.find({value[id], id}) == q.end()) continue;
        q.erase(q.find({value[id], id}));
        value[id] = query(sy + dy, sx + dx);
        q.insert({value[id], id});
      }
    }
  };

  for (int y = 0; y < N; y++)
    for (int x = 0; x < N; x++) {
      int id = make_xy(y, x);
      value[id] = query(y, x);
      q.insert({value[id], id});
    }

  for (auto [v, id]: q) {
    auto [y, x] = unmake_xy(id);
    // printf("> %llu at (%llu %llu)\n", v, y, x);
  }

  int A = 0, B = 0;
  int* S1 = &A, * S2 = &B;
  auto it = q.begin();
  while (it != q.end()) {
    auto [v, id] = *it;
    // printf("%llu %llu\n", v, id);
    *S1 += v;
    auto [y, x] = unmake_xy(id);
    rem(y, x);
    swap(S1, S2);

    auto bf = it;
    it++;
    q.erase(bf);

    for (auto [v, id]: q) {
      auto [y, x] = unmake_xy(id);
      // printf("> %llu at (%llu %llu)\n", v, y, x);
    }
  }

  printf("%llu %llu\n", A, B);

  // Solution ends here

#ifdef TEST_CASESS
  }
#endif
}