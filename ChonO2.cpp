#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define f first
#define s second
#define all(C) C.begin(), C.end()
#define Begin() int N; cin>>N; cin.ignore(); while(N--)
#define FOR(i,a,b) for (ll i=(ll)a; i<=(ll)b; i++)
#define FORD(i,a,b) for (ll i=(ll)a; i>=(ll)b; i--)
#define reset(C) memset(C,0,sizeof(C))
#define Fill(C,a) fill(C.begin(), C.end(), a)
#define SORT(C) sort(C.begin(), C.end())
#define SORTD(C,x) sort(C.begin(), C.end(), greater<x>())
#define SORTC(C,check) sort(C.begin(), C.end(), check)
#define Merge(C,F,K) merge(C.begin(), C.end(), F.begin(), F.end(), K.begin());
#define Unique(C) C.erase(unique(C.begin(), C.end()), C.end())
#define revrs(C) reverse(C.begin(), C.end())
#define getVector(C) for(ll _=0; _<C.size(); _++) cin>>C[_]
#define printVector(C) for(int _=0; _<C.size(); _++) cout<<C[_]<<' '
#define p(x,y) pair<x,y> 
#define vec(x) vector<x> 
#define Matrix(x) vector<vector<x> >
#define Rubik(x) vector<vector<vector<x> > >
#define pq(x) priority_queue<x>
#define reverse_pq(x) priority_queue<x, vector<x>, greater<x> >
#define ordered_set(T) tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset(T) tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
using namespace __gnu_pbds;

ld PI = 3.14159265358979323846;

ld eps = 1e-4;

//ll M = 1e9 + 7;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll DP[17][10005];

ll C[5][10005];

ll calc(ll j, ll i)
{
	ll y = 0;
	FOR(k, 1, 4)
	{
		ll x = 1LL << (k - 1);
		if (x & j) y += C[k][i];
	}
//	ll y = C[1][i] * (j & 1) + C[2][i] * (j & 2) / 2 + C[3][i] * (j & 4) / 4 + C[4][i] * (j & 8) / 8;
	return y;
}

void Process()
{
	ll a;
	cin >> a;
	reset(DP);
	reset(C);
	FOR(i, 1, 4)
	{
		FOR(j, 1, a)
		{
			cin >> C[i][j];
		}
	}
	FOR(i, 0, 15)
	{
		FOR(j, 0, a) DP[i][j] = -2e18;
	}
	FOR(i, 1, 10)
	{
		if (i == 3 || i == 6 || i == 7) continue;
		DP[i][1] = calc(i, 1);
//		DP[i][1] = 0;
//		FOR(j, 1, 4)
//		{
//			ll x = 1LL << (j - 1);
//			if (x & i) DP[i][1] += C[j][1];
//		}
	}
	FOR(i, 2, a)
	{
		FOR(k, 0, 10)
		{
			if (k == 3 || k == 6 || k == 7) continue;
			DP[k][i] = calc(k, i);
			ll c = 0;
			FOR(j, 0, 10)
			{
				if (j == 3 || j == 6 || j == 7) continue;
				if (j & k) continue;
				ll y = calc(k, i);
				DP[k][i] = max(DP[k][i], DP[j][i - 1] + y);
				c++;
			}
			if (c == 0) DP[k][i] = -2e18;
		}
	}
	ll ans = -2e18;
	FOR(i, 0, 10)
	{
		if (i == 3 || i == 6 || i == 7) continue;
		FOR(j, 1, a) ans = max(ans, DP[i][j]);
	}
//	if (ans == 0)
//	{
//		ans = -2e18; FOR(i, 1, 4) FOR(j, 1, a) ans = max(ans, C[i][j]);
//	}
	cout << ans << endl;
}

signed main() 
{
	faster();
	Begin()
	{
		Process();
	}
}

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                               Coded by thanhchauns2                                //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////
