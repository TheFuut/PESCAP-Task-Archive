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
  // return 1;

#ifdef TEST_CASES
  uint TTT;
  scanf("%llu", &TTT);
  while (TTT--) {
#endif

  // Solution starts here

  uint N, Q;
  scanf("%llu%llu", &N, &Q);

  set<uint> line;
  auto doeswork = [&](uint num, uint diff) {
    auto it = line.begin();
    auto it2 = gen[num].begin();

    while (it != line.end()) {
      if ((*it2 + diff) > *it)
        return false;
      while (it2 != gen[num].end() && (*it2 + diff) <= *it)
        it2++;
      it++;
      if (it != line.end() && it2 == gen[num].end()) return false;
    }

    return true;
  };

  auto doeswork_pid = [&](uint num) -> uint {
    uint m = *line.begin();
    bool w = 0;
    for (uint s = m; s > 0; s--)
      if (doeswork(num, s)) return s;
    return 0;
  };

  for (uint x = 0; x < N; x++) {
    uint e;
    scanf("%llu", &e);
    line.insert(e);
  }

  set<uint> works = {1};
  for (uint x = 2; x < 10001; x++) {
    if (doeswork_pid(x)) works.insert(x);
  }

#ifdef DEBUG
  for (uint x: works) printf("%llu ", x);
  printf("\n");
#endif

  while (Q--) {
    uint t;
    scanf("%llu", &t);

    if (t == 1) {
      if (line.size() < 2) {
        printf("%lu\n", line.size());
        continue;
      }

      uint ans = ULLONG_MAX, first = *line.begin();
      auto it = --line.end();
      --it;
      // printf("> %llu\n", *it);

      for (uint x: works) {
        uint sp = doeswork_pid(x);
        ans = min(((*it - sp) / x) + 2, ans);
#ifdef DEBUG
        printf(">> %llu(%llu - %llu = %llu) -> %llu\n", x, *it, sp, *it - sp, ans);
#endif
      }

      printf("%llu\n", ans);
      continue;
    }

    uint e;
    scanf("%llu", &e);
    line.insert(e);

    auto it = ++works.begin();
    while (it != works.end()) {
      if (!doeswork_pid(*it)) {
        auto bf = it;
        it++;
        works.erase(bf);
      } else it++;
    }

#ifdef DEBUG
    for (uint x: works) printf("%llu ", x);
    printf("\n");
#endif
  }

  // Testing time limits. This probably wont work!
  // Solution ends here

#ifdef TEST_CASES
  }
#endif
}