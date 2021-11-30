#include <bits/stdc++.h>
#define ll long long
#define Begin() int N; cin>>N; cin.ignore(); while(N--)
#define FOR(_, a, b) for (ll _ = (ll)a; _ <= (ll)b; _++)
#define FORD(_, a, b) for (ll _ = (ll)a; _ >= (ll)b; _--)
#define printVector(C) for(int _=0; _<C.size(); _++) cout<<C[_]<<' '
#define reset(C) memset(C,0,sizeof(C))
#define SORT(C) sort(C.begin(), C.end())
#define Matrix(x) vector<vector<x> >
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define getVector(C) for(ll _=0; _<C.size(); _++) cin>>C[_]
#define pb push_back
#define p pair
#define f first
#define s second
using namespace std;

const ll M = 1e15 + 7;

ll n;

ll POW[1000005];

ll PREF[2000005];

ll SUFF[2000005];

ll secure(ll a)
{
	while (a < 0) a += M;
	return a;
}

void build()
{
	FORD(i, n - 1, 1)
	{
		PREF[i] = PREF[i << 1] + PREF[i << 1 | 1];
		PREF[i] %= M;
		SUFF[i] = SUFF[i << 1] + SUFF[i << 1 | 1];
		SUFF[i] %= M;
	}
}

void modifypref(ll idx, ll value)
{
	for (PREF[idx += n] = value; idx > 1; idx >>= 1) PREF[idx >> 1] = (PREF[idx] + PREF[idx ^ 1]) % M;
}

void modifysuff(ll idx, ll value)
{
	for (SUFF[idx += n] = value; idx > 1; idx >>= 1) SUFF[idx >> 1] = (SUFF[idx] + SUFF[idx ^ 1]) % M;
}

void modify(ll idx, ll value)
{
	ll pref = value * POW[idx] % M;
	ll suff = value * POW[n - idx - 1] % M;
	modifypref(idx, pref);
	modifysuff(idx, suff);
}

ll getpref(ll l, ll r)
{
	ll ans = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1) ans = (ans + PREF[l++]) % M;
		if (r & 1) ans = (ans + PREF[--r]) % M;
	}
	return ans;
}

ll getsuff(ll l, ll r)
{
	ll ans = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1) ans = (ans + SUFF[l++]) % M;
		if (r & 1) ans = (ans + SUFF[--r]) % M;
	}
	return ans;
}

ll mul(ll a, ll b)
{
    if (b == 0) return 0;
    ll t = mul(a, b / 2);     	
    t = (t + t) % M; 
    if (b % 2 == 1) t = (t + a) % M;
    return t;
} 

void Process()
{
	reset(PREF);
	reset(SUFF);
	string s;
	cin >> s;
	n = s.length();
	POW[0] = 1;
	FOR(i, 1, 1000000)
	{
		POW[i] = POW[i - 1] * 10 % M;
	}
	FOR(i, 0, n - 1)
	{
		PREF[i + n] = (s[i] - '0') * POW[i] % M;
		SUFF[i + n] = (s[i] - '0') * POW[n - 1 - i] % M;
	}
//	FOR(i, 1, n - 1)
//	{
//		PREF[i + n] += PREF[i - 1 + n];
//		PREF[i + n] %= M;
//	}
//	FORD(i, n - 2, 0)
//	{
//		SUFF[i + n] += SUFF[i + 1 + n];
//		SUFF[i + n] %= M;
//	}
	build();
	ll q;
	cin >> q;
	while(q--)
	{
		char x;
		ll l, r;
		cin >> x >> l >> r;
		if (x == 'c')
		{
			modify(l - 1, r);
		}
		else
		{
			ll pref = getpref(l - 1, r);
			ll suff = getsuff(l - 1, r);
			ll lft = l - 1;
			ll rgt = n - r;
			ll del = lft - rgt;
			if (del < 0)
			{
				pref = mul(pref, POW[-del]);
				pref %= M;
			}
			else
			{
				suff = mul(suff, POW[del]);
				suff %= M;
			}
			if (pref == suff) cout << "YES" << '\n';
			else cout << "NO" << '\n';
//			cout << pref << ' ' << suff << '\n';
		}
//		FOR(i, 0, n - 1)
//		{
//			cout << getpref(i, i + 1) << ' ';
////			cout << PREF[i] << ' ';
//		}
//		cout << '\n';
//		FOR(i, 0, n - 1)
//		{
//			cout << getsuff(i, i + 1) << ' ';
////			cout << SUFF[i] << ' ';
//		}
//		cout << '\n';
	}
}

signed main() 
{
	faster();
//	Begin()
//	{
		Process();
//	}
}
