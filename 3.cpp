// Author : Mars_Coder


#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

#define ln              "\n" // no flush, oppos of endl
#define _flush          endl
#define stop_sync       ios::sync_with_stdio(false) // not to use c-stye io
#define untie_ios       cin.tie(nullptr) // no flush
#define lli             long long int
#define vi              vector<int>
#define vii             vector<lli>
#define vss             vector<string>
#define pb              push_back
#define ppb 	        pop_back
#define sz(x)           ((x).size())
#define all(x)          (x).begin(), (x).end()
#define bin_sc(a, x)    binary_search(all(a), x)
#define lbd(a, x)       lower_bound(all(a), x) // an iter.
#define ubd(a, x)       upper_bound(all(a), x) // an iter.
#define eq_seg(a, x)    equal_range(all(a), x) // a pair of lb, ub
#define FIXED(x)        cout << fixed << setprecision(x)
const long double PI = acos(-1.0L);

lli max_factor(lli n){
	lli ans;
	while(n % 2 == 0){
		n /= 2;
		ans = 2;
	}
	for(lli d = 3; d * d <= n; d += 2){
		if(n == 1) break;
		while(n % d == 0){
			n /= d;
			ans = d;
		}
	}
	if(n > 1) ans = n;
	return ans;
}
int main(void){
	lli n;
	cin >> n;
	cout << max_factor(n) << ln;
	return 0;
}


/*
some familiar issues:
----> [look at global variables and their values]
----> [llabs() for long long int type]

*/


