#include <bits/stdc++.h>
using namespace std;
long long a, b, n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  long long contador = n;
  for (int i = 0; i < n; i++){
    cin >> a >> b;
    if (a >= b){
        contador--;
    }
  }
   cout << contador;



  return 0;
}