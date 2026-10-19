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

signed main() {
#ifdef TEST_CASES
  uint TTT;
  scanf("%llu", &TTT);
  while (TTT--) {
#endif

  // Solution starts here

  uint N, K;
  scanf("%u%u", &N, &K);

  uint src[N];
  for (uint x = 0; x < N; x++)
    scanf("%u", &src[x]), src[x]--;

  uint dst[N];
  for (uint x = 0; x < N; x++)
    scanf("%u", &dst[x]), dst[x]--;

  uint oc = 0;
  for (uint i = 0; i <= N - K; i++) {
    char n = src[i];
    char obj = dst[i];
    if (n == obj) continue;
    char mask = n ^ obj;
    oc += __builtin_popcount(mask);
    for (uint x = 0; x < K; x++)
      src[i + x] ^= mask;
  }

  bool g = 1;
  for (uint i = N - K + 1; i < N; i++) {
    if (src[i] == dst[i]) continue;
    g = 0;
    break;
  }

  if (g == 0) printf("-1\n");
  else printf("%d\n", oc);

  // Solution ends here

#ifdef TEST_CASESS
  }
#endif
}