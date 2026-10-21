#include <bits/stdc++.h>
using namespace std;

long long N, K, X, A;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
	for (long long i = 0; i < N; i++){
		cin >> X;
		A += X;
	}
 	if (A >= X) {
 		cout << "Dulces para todos";
	} else {
		cout << "Sin dulces";
	}
	return 0;
}