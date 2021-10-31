#include <bits/stdc++.h>
#define ll long long
#define Begin() int N; cin>>N; cin.ignore(); while(N--)
#define FOR(_, a, b) for (ll _ = (ll)a; _ <= (ll)b; _++)
#define reset(C) memset(C,0,sizeof(C))
#define Matrix(x) vector<vector<x> >
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back()
using namespace std;

ll powermod(ll a, ll b, ll m)
{
	if (b == 0) return 1;
	ll k = powermod(a, b / 2, m);
	k = k * k;
	k %= m;
	if (b & 1) k = (k * a) % m;
	return k;
}

ll M;

ll a;

ll FACT[1000005];

ll inv(ll x)
{
	return powermod(x, M - 2, M);
}

Matrix(ll) I = {{1, 1}, {1, 0}};

Matrix(ll) mul(Matrix(ll) A, Matrix(ll) B)
{
	Matrix(ll) C = A;
	FOR(i, 0, 1)
	{
		FOR(j, 0, 1)
		{
			C[i][j] = 0;
			FOR(k, 0, 1)
			{
				C[i][j] += A[i][k] * B[k][j];
				C[i][j] %= M;
			}
		}
	}
	return C;
}

Matrix(ll) Expo(Matrix(ll) X, ll a)
{
	if (a <= 1) return X;
	Matrix(ll) K = Expo(X, a / 2);
	K = mul(K, K);
	if (a & 1) K = mul(K, I);
	return K;
}

ll Fibo(ll a)
{
	return Expo(I, a)[0][0];
}

ll base;

ll get_the_power(ll i, ll mod)
{
	if (i % M != 0) return 1;
	ll l = 1, r = base;
	while (l <= r)
	{
		ll mid = (l + r) / 2;
		ll k = powermod(M, mid, 1e18);
		if (i % k == 0)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	return powermod(M, l - 1, 1e18);
}

void Process()
{
	cin >> a >> M;
	ll x = 0, y = 0;
	base = 0;
	ll N = 1;
	if (M == 1)
	{
		cout << 0 << endl;
		return;
	}
	while (a >= N)
	{
		base++;
		N *= M;
	}
	if (a % 2 == 0)
	{
		y = a / 2 + 1;
		y = -y;
		y = y % M;
		if (y < 0) y += M;
		ll k = 0, q = 0;
		for (ll _ = M; _ <= a / 2; _ *= M)
		{
			k += (a / 2) / _;
		}
		for (ll _ = M; _ <= a; _ *= M)
		{
			q += a / _;
		}
		if ((q - k * 2) <= 0)
		{
			ll p1 = 1, p2 = 1;
			FOR(i, 2, a / 2)
			{
				ll k = i;
				ll q = get_the_power(i, M);
				k /= q;
				p1 = p1 * k;
				p1 %= M;
			}
			p2 = p1;
			FOR(i, a / 2 + 1, a)
			{
				ll k = i;
				ll q = get_the_power(i, M);
				k /= q;
				p2 = p2 * k;
				p2 %= M;
			}
			x = p2 * p1;
			x = p2 * inv(p1) % M;
			x = x * inv(p1) % M;
		}
	}
	ll z = Fibo(a + 1);
	cout << (z + x + y) % M << endl;
}

signed main()
{
	faster();	
	Begin()
	{
		Process();
	}
}
