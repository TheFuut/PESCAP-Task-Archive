#include <bits/stdc++.h>
using namespace std;

long long N, X, D, Hola[50000];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
cin >> N;

	for(long long i=0; i<N; i++){
		cin >> X >> D;
		
		for(long long j=0; j<X; j++){
			cin >> Hola[j];
		}
		
		if(Hola[0]+Hola[X-1] < D){
			cout << "NO" << "\n";
		}
		else{
			cout << "SI" << "\n";
		}
	}

	return 0;
}