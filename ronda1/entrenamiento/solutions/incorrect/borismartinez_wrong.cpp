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

template<class T>
using triplet = tuple<T, T, T>;

signed main() {
  vector<vector<uint>> gen(10001, vector<uint>(1, 0));
  for (uint x = 1; x < gen.size(); x++) {
    while (gen[x].back() + x <= 10001)
      gen[x].push_back(gen[x].back() + x);
  }

  // for (auto &v: gen | views::reverse) {
  //   printf("(%llu, %llu):", v.size(), v.back() / (v.size() - 1));
  //   for (uint i: v) printf(" %llu", i);
  //   printf("\n");
  // }

#ifdef TEST_CASES
  uint TTT;
  scanf("%llu", &TTT);
  while (TTT--) {
#endif

  // Solution starts here

  uint N, Q;
  scanf("%llu%llu", &N, &Q);

  set<uint> line;
  auto doeswork = [&](uint num) {
    auto it = line.begin();
    auto it2 = ++gen[num].begin();
    if (it2 == gen[num].end()) return false;

    while (it != line.end()) {
      if (*it2 > *it)
        return false;
      while (it2 != gen[num].end() && *it2 <= *it)
        it2++;
      it++;
      if (it != line.end() && it2 == gen[num].end()) return false;
    }

    return true;
  };

  for (uint x = 0; x < N; x++) {
    uint e;
    scanf("%llu", &e);
    line.insert(e);
  }

  set<uint> works = {1};
  for (uint x = 2; x < 10001; x++) {
    if (doeswork(x)) works.insert(x);
  }

  while (Q--) {
    uint t;
    scanf("%llu", &t);

    if (t == 1) {
      if (line.size() < 2) {
        printf("%lu\n", line.size());
        continue;
      }

      uint ans = ULLONG_MAX;
      auto it = --line.end();
      --it;
      // printf("> %llu\n", *it);

      for (uint x: works) {
        ans = min((*it / x) + 1, ans);
        // printf(">> %llu -> %llu\n", x, ans);
      }

      printf("%llu\n", ans);
      continue;
    }

    uint e;
    scanf("%llu", &e);
    line.insert(e);

    auto it = ++works.begin();
    while (it != works.end()) {
      if (!doeswork(*it)) {
        auto bf = it;
        it++;
        works.erase(bf);
      } else it++;
    }
  }

  // Solution ends here

#ifdef TEST_CASES
  }
#endif
}