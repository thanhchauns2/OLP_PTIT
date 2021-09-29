// Designed by Nguyen Thanh Chau
// a.k.a Paperback Collector
// En Taro Adun! - TemplarAssasin a.k.a Zeratul

//                #####                #####
//              ###    ####        ####    ###
//             ##         ###    ###         ##
//             ##            ####            ##
//             ##            ####            ##
//             ##          ##    ##          ##
//             ##        ###      ###        ##
//              ##  ######################  ##
//           ######    ###          ###    ######
//       ###    ##    ##              ##    ##    ###
//    ###        ## ###      ####      ### ##       ###
//   ##	          ####     ########     ####          ##
//  ##            ###     ##########     ###           ##
//   ##	          ####     ########     ####          ##
//    ###        ## ###      ####      ### ##       ###
//       ###    ##    ##              ##    ##    ###
//           ######    ###          ###    ######
//              ##  ######################  ##
//             ##        ###      ###        ##
//             ##          ##    ##          ##
//             ##            ####            ##
//             ##            ####            ##
//             ##         ###    ###         ##
//              ###    ####        ####    ###
//                #####                #####


////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                Libraries and stuffs                                //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////

// Libraries

#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <boost/math/constants/constants.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
//#include <boost/cstdint.hpp>

// Defines
	
	// Typedefs
	
//    #define ll cpp_int
	#define ll long long
	#define ld long double
	#define ull unsigned long long
	#define pb push_back
	#define eb emplace_back
	#define cl(C) C.clear()
	#define f first
	#define s second
	#define cint cpp_int
	#define nl << '\n'
	#define all(C) C.begin(), C.end()
	#define Begin() int N; cin>>N; cin.ignore(); while(N--)
	
	//Commands
	
		// Loops
		
		#define FOR(i,a,b) for (ll i=a; i<=b; i++)
		#define FOR2(i,a,b) for (ll i=a; i<=b; ++i)
		#define FORD(i,a,b) for (ll i=a; i>=b; i--)
		#define FORA(x,C) for (auto x:C)
		#define WHILE(x,y) while(cin>>x>>y)
		#define WHILEF(x,y,f) while(f>>x>>y)
		#define WHILE2(x) while(cin>>x)
		#define WHILEGL(a) while(getline(cin,a))
		#define WHILEGLF(a,f) while(getline(f,a))
		
		// Get values
		
		#define maxOf(C) max_element(C.begin(), C.end()) - C.begin()
		#define minOf(C) min_element(C.begin(), C.end()) - C.begin()
		#define ite(y,x,it) y<x>::iterator it
		
		// Clear containers
		
		#define reset(C) memset(C,0,sizeof(C))
		#define clearQueue(C, x) C = queue<x> ()
		#define Fill(C,a) fill(C.begin(), C.end(), a)
		
		// Customize containers
		
		#define SORT(C) sort(C.begin(), C.end())
		#define SORTD(C,x) sort(C.begin(), C.end(), greater<x>())
		#define SORTC(C,check) sort(C.begin(), C.end(), check)
		#define tlw(C) for(int i=0; i<(sizeof(C)/sizeof(C[0])); i++) C[i] = tolower(C[i])
		#define tup(C) for(int i=0; i<(sizeof(C)/sizeof(C[0])); i++) C[i] = toupper(C[i])
		#define Merge(C,F,K) merge(C.begin(), C.end(), F.begin(), F.end(), K.begin());
		#define Unique(C) C.erase(unique(C.begin(), C.end()), C.end())
		#define CutInHalf(C,F,x,y) y<x> F(C.begin() + C.size()/2 + 1, C.end()); C.resize(C.size()/2)
		#define revrs(C) reverse(C.begin(), C.end())
		
		// Scan and print containers
		
		#define get(C,a) for(int i=0; i<a; i++) cin>>C[i]
		#define get2(C,a,b) for(int i=0; i<a; i++) for (int j=0; j<b; j++) cin>>C[i][j]
		#define getVector(C) for(ll _=0; _<C.size(); _++) cin>>C[_]
		#define getMatrix(C) for(int i=0; i<C.size(); i++) for (int j=0; j<C[i].size(); j++) cin>>C[i][j]
		#define getDeque(C) for(int i=0; i<C.size(); i++) cin>>C[i]
		#define getSet(C, a, token) for(int i=0; i<a-1; i++) { cin>>token; C.insert(token); } cin>>token; C.insert(token)
		#define print(C,a) for(int i=0; i<a; i++) cout<<C[i]<<' '
		#define printVector(C) for(int _=0; _<C.size(); _++) cout<<C[_]<<' '
		#define printSet(C,x) for (set<x>::iterator it = C.begin(); it!= C.end(); ++it) cout<<*it<<' '
		#define printDeque(C) for(int i=0; i<C.size(); i++) cout<<C[i]<<' '
		
		// Converts between containers
		
		#define toSet(C,x) set<x> (C.begin(), C.end())
		#define toVector(C,x) vector<x> (C.begin(), C.end())
		#define toQueue(C,x) queue<x> (C.begin(), C.end())
		#define toDeque(C,x) deque<x> (C.begin(), C.end())
		#define toList(C,x) list<x> (C.begin(), C.end())
		#define toMultiset(C,x) multiset<x> (C.begin(), C.end())
		
		// Iterators
		
		#define pointer(A,x) A<x>::iterator
		
	// Containers
	
	#define um(x,y) unordered_map<x,y> 
	#define m(x,y) map<x,y> 
	#define p(x,y) pair<x,y> 
	#define us(x) unordered_set<x> 
	#define vec(x) vector<x> 
	#define Matrix(x) vector<vec(x)>
	#define Rubik(x) vector<Matrix(x)>
	#define vec2(C,x,y,token) vector<vector<token> > C(x, vector<token> (y, 0))
	#define pq(x) priority_queue<x>
	#define reverse_pq(x) priority_queue<x, vector<x>, greater<x> >
	#define ordered_set(T) tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
	#define ordered_multiset(T) tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>
	
	// System
	
	#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#define pause() system("pause");

// Namespaces

using namespace std;
using namespace __gnu_pbds;
// using namespace __gnu_cxx;
// using namespace __gnu_debug;
// using namespace __gnu_internal; //	GNU implemenation details, not for public use or export. Used only when anonymous namespaces cannot be substituted
// using namespace __gnu_parallel; //	GNU parallel code for public use
// using namespace __gnu_pbds; //	GNU extensions for policy-based data structures for public use
// using namespace __gnu_profile; //	GNU profile code for public use
// using namespace __gnu_sequential;
// using namespace boost::multiprecision;
// using boost::multiprecision::cpp_dec_float_50;

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                               A few extra functions                                //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////

multiset<ll> LIS(vector<ll> A)
{
	ll a = A.size();
	multiset<ll> S;
	multiset<ll>::iterator it;
	FOR(i, 0, a - 1)
	{
		S.insert(A[i]);
		it = S.upper_bound(A[i]);
		if (it != S.end()) S.erase(it);
	}
	return S;
}

multiset<ll> LSIS(vector<ll> A) // a.k.a Longest Strictly Increasing Sequence
{
	ll a = A.size();
	multiset<ll> S;
	multiset<ll>::iterator it;
	FOR(i, 0, a - 1)
	{
		S.insert(A[i]);
		it = S.lower_bound(A[i]);
		it++;
		if (it != S.end()) S.erase(it);
	}
	return S;
}

ll gcd(ll a, ll b)	
{
	if (a == 0) return(b);
	return(gcd(b % a, a));
}

ll extGcd(ll a, ll b, ll& x, ll& y) // returns d=gcd(a,b), and give one pair x,y such that ax+by=d
{
	if(a==0)
	{
		x=0;y=1;
		return(b);
	}
	ll a1, b1, c, x1, y1, rst;
	a1 = b % a; b1 = a; c = b / a;
	rst = extGcd(a1, b1, x1, y1);
	x = y1 - c * x1; y = x1;
	return(rst);
}

// Prime test for large numbers

bool suspect(ll b, ll t, ll u, ll n)
{
	ll prod = 1;
	while(u)
	{
		if(u & 1) prod=((prod * b) % n);
		b=((b * b) % n);
		u /= 2;
	}
	if(prod == 1) return true;
	FOR(i, 1, t)
	{
		if(prod == n - 1) return true;
		prod = (prod * prod) % n;
	}
	return false;
}

bool isprime(ll n)
{
	ll k = n - 1;
	ll t = 0;
	while(!(k % 2)) 
	{
		t++; 
		k /= 2; 
	}
	if(n > 2 && n % 2 == 0) return 0;
	if(n > 3 && n % 3 == 0) return 0;
	if(n > 5 && n % 5 == 0) return 0;
	if(n > 7 && n % 7 == 0) return 0;
	if(suspect(61, t, k, n) && suspect(7, t, k, n) && suspect(2, t, k, n)) return true;
	return false;
}

bool isprimell(ull n)
{
	ll k = n - 1;
	ll t = 0;
	while(!(k % 2)) 
	{
		t++; 
		k /= 2; 
	}
	if(n > 2 && n % 2 == 0) return 0;
	if(n > 3 && n % 3 == 0) return 0;
	if(n > 5 && n % 5 == 0) return 0;
	if(n > 7 && n % 7 == 0) return 0;
	if(suspect(3, t, k, n) && suspect(7, t, k, n) && suspect(2, t, k, n) && suspect(5, t, k, n) && suspect(11, t, k, n) && suspect(13, t, k, n) && suspect(17, t, k, n) && suspect(19, t, k, n) && suspect(19, t, k, n) && suspect(23, t, k, n) && suspect(29, t, k, n) && suspect(31, t, k, n) && suspect(37, t, k, n)) return true;
	return false;
}

// End of function

// Treap

struct Treap // multiset supporting duplicating values in set
{
    ll len = 0;
    const ll ADD = 1000010;
    const ll MAXVAL = 1000000010;
    map<ll, ll> mp; // hash = 96814
    tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> T;
    tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>::iterator it;

    Treap() { len = 0; T.clear(), mp.clear(); }

    inline void insert(ll x)
	{
        len++, x += MAXVAL;
        int c = mp[x]++;
        T.insert((x * ADD) + c); 
	}
    
    inline void erase(ll x)
	{
        x += MAXVAL;
        ll c = mp[x];
        if(c) 
		{
            c--, mp[x]--, len--;
            T.erase((x*ADD) + c); 
		} 
	}
    inline ll kth(ll k) // 1-based index,  returns the
	{       
        if(k<1 || k>len) return -1;     // K'th element in the treap,
        it = T.find_by_order(--k); // -1 if none exists
        return ((*it)/ADD) - MAXVAL;
	} 
    
    inline ll lower_bound(ll x) // Count of value <x in treap
	{     
        x += MAXVAL;
        ll c = mp[x];
        return (T.order_of_key((x*ADD)+c)); 
	}

    inline ll upper_bound(ll x) // Count of value <=x in treap
	{     
        x += MAXVAL;
        ll c = mp[x];
        return (T.order_of_key((x*ADD)+c)); 
	}
 
    inline ll size() { return len; }   // Number of elements in treap
};

// End of function

// Segment tree

class SegTree2
{
	ll size;
	vec(ll) base;
	public:
		void build()
		{
			for (int i = size - 1; i > 0; --i) base[i] = base[i << 1] + base[i << 1 | 1];
		}
		void getbase(ll x)
		{
			size = x;
			base.resize(x * 2);
			build();
		}
		ll sumrange(ll l, ll r) // Get the sum in range [l, r)
		{
			ll res = 0;
			for (l += size, r += size; l < r; l >>= 1, r >>= 1) 
			{
			    if (l & 1) res += base[l++];
			    if (r & 1) res += base[--r];
			}
			return res;
		}
		void updatenum(ll idx, ll value) 
		{
			for (base[idx += size] = value; idx > 1; idx >>= 1) base[idx >> 1] = base[idx] + base[idx ^ 1];
		}
		void updaterange(ll l, ll r, ll value) 
		{
			for (l += size, r += size; l < r; l >>= 1, r >>= 1) 
			{
			    if (l & 1) base[l++] += value;
			    if (r & 1) base[--r] += value;
			}
		}
		ll at(ll idx) 
		{
			int res = 0;
			for (idx += size; idx > 0; idx >>= 1) res += base[idx];
			return res;
		}
};

// End of function

// String operations

class STRO
{
	public:
		bool bigger(string a, string b)
		{
			if (a.length() > b.length()) return true;
			if (a.length() < b.length()) return false;
			FOR(i, 0, a.length() - 1)
			{
				if (a[i] > b[i]) return true;
				else if (a[i] < b[i]) return false;
			}
			return false;
		}
		
		string add(string str1, string str2) // add strings
		{
		    if (str1.length() > str2.length())
		        swap(str1, str2);
		    string str = "";
		    int n1 = str1.length(), n2 = str2.length();
		    int diff = n2 - n1;
		    int carry = 0;
		    for (int i=n1-1; i>=0; i--)
		    {
		        int sum = ((str1[i]-'0') + (str2[i+diff]-'0') + carry);
		        str.push_back(sum%10 + '0');
		        carry = sum/10;
		    }
		    for (int i=n2-n1-1; i>=0; i--)
		    {
		        int sum = ((str2[i]-'0')+carry);
		        str.push_back(sum%10 + '0');
		        carry = sum/10;
		    }
		    if (carry) str.push_back(carry+'0');
		    reverse(str.begin(), str.end());
		    while(str.size() > 1 && str[0] == '0') str.erase(0, 1);
		    return str;
		}
		
		string sub(string str1, string str2) // substract strings
		{
		    if (bigger(str2, str1)) swap(str1, str2);
		    string str = "";
		    int n1 = str1.length(), n2 = str2.length();
		    reverse(str1.begin(), str1.end());
		    reverse(str2.begin(), str2.end());
		    int carry = 0;
		    for (int i = 0; i < n2; i++) 
			{
		        int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);
		        if (sub < 0) {
		            sub = sub + 10;
		            carry = 1;
		        }
		        else
		            carry = 0;
		 
		        str.push_back(sub + '0');
		    }
		    for (int i = n2; i < n1; i++) 
			{
		        int sub = ((str1[i] - '0') - carry);
		        if (sub < 0) {
		            sub = sub + 10;
		            carry = 1;
		        }
		        else
		            carry = 0;
		 
		        str.push_back(sub + '0');
		    }
		    reverse(str.begin(), str.end());
		    while (str.size() > 1 && str[0] == '0') str.erase(0, 1);
		    return str;
		}
		
		string mul(string A, string B) // multiply strings
		{
			reverse(A.begin(),A.end());
			reverse(B.begin(),B.end());
			string C;
			C.resize(A.length() + B.length(),'0');
			FOR(i, 0, A.length()-1)
			{
				int c = 0;
				FOR(j, 0, B.length()-1)
				{
					c += ((A[i] - '0') * (B[j] - '0') + C[i + j] - '0');
					C[i + j] = (char)(c%10 + '0');
					c/=10;
				}
				if (c > 0) C[i + B.length()] += c;
			}
			reverse(C.begin(),C.end());
			while (C.size() > 1 && C[0] == '0') C.erase(0, 1);
			return C;
		}
		string div(string number, ll divisor) // divide strings
		{
		    string ans = "";
		    ll idx = 0;
		    ll temp = number[idx] - '0';
		    while (temp < divisor) temp = temp * 10 + (number[++idx] - '0');
		    while (number.size() > idx) 
			{
		        ans += (temp / divisor) + '0';
		        temp = (temp % divisor) * 10 + number[++idx] - '0';
		    }
		    while (ans.size() > 1 && ans[0] == '0') ans.erase(0, 1);
		    if (ans.length() == 0) return "0";
		    return ans;
		}
		bool bigger2(string a, string b)
		{
			if (a.length() > b.length()) return true;
			if (a.length() < b.length()) return false;
			FOR(i, 0, a.length() - 1)
			{
				if (a[i] > b[i]) return true;
				else if (a[i] < b[i]) return false;
			}
			return true;
		}
		string dv(string a, string b)
		{
			if (bigger(b, a)) return "0";
			if (a == "0") return "0";
			string l = "0";
			string r = a;
			string mid, mid2;
			while (bigger2(r, l))
			{
				mid = add(r, l);
				if ((mid[mid.length() - 1] - '0') % 2 == 1) mid[mid.length() - 1]--;
				mid = div(mid, 2);
				if (mid == "0") break;
				mid2 = mul(mid, b);
				if (bigger(mid2, a)) r = sub(mid, "1");
				else l = add(mid, "1");
			}
			return r;
		}
		string md(string a, string b)
		{
			if (bigger(b, a)) return a;
			if (a == "0") return "0";
			if (b == "1") return "0";
			string l = "0";
			string r = a;
			string mid, mid2;
			while (bigger2(r, l))
			{
				if (mid == "0") break;
				mid = add(r, l);
				if ((mid[mid.length() - 1] - '0') % 2 == 1) mid[mid.length() - 1]--;
				mid = div(mid, 2);
				mid2 = mul(mid, b);
				if (bigger(mid2, a)) r = sub(mid, "1");
				else l = add(mid, "1");
			}
			mid = mul(r, b);
			mid = sub(a, mid);
			while (mid.size() > 1 && mid[0] == '0') mid.erase(0, 1);
			if (mid == b) return "0";
			return mid;
		}
		string strgcd(string a, string b)
		{
			if (a == "0") return b;
			return strgcd(md(b, a), a);
		}
};

STRO STR;

// End of function

//void pr(__int128 x)
//{
//	if (x < 0) putchar('-'), x = -x;
//	if (x > 9) pr(x / 10);
//	putchar(x % 10 + '0');
//}
//
//__int128 rd()
//{
//	__int128 x = 0, f = 1;
//	char ch = getchar();
//	while (ch < '0' || ch > '9')
//	{
//		if (ch == '-') f = -1;
//		ch = getchar();
//	}
//	while(ch >= '0' && ch <= '9')
//	{
//		x = x * 10 + ch - '0';
//		ch = getchar();
//	}
//	return x * f;
//}

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                     Constants                                      //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////

ld PI = 3.14159265358979323846;

ld eps = 1e-9;

//ll M = 998244353;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                     End of preparation, your code starts HERE                      //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////

//struct ele
//{
//};

bool __isprime(ll x)
{
	if (x < 2) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	if (x == 3) return true;
	if (x % 3 == 0) return false;
	ll t = 1;
	for (ll i = 5; i * i <= x; i += 2 * (1 + t))
	{
		if (x % i == 0) return false;
		t = 1 - t;
	}
	return true;
}

ll dist(p(ll, ll) a, p(ll, ll) b)
{
	ll x = (a.f - b.f) * (a.f - b.f);
	ll y = (a.s - b.s) * (a.s - b.s);
	return x + y;
}

ll powermod(ll a, ll b, ll m)
{
	if (b == 0) return 1;
	ll k = powermod(a, b / 2, m);
	k = k * k;
	k %= m;
	if (b & 1) k = (k * a) % m;
	return k;
}

//bool cmp(p(ll, ll) a, p(ll, ll) b)
//{
//	if (a.f == b.f) return a.f > b.f;
//	return a.s > b.f;
//}
//#define ll long long
//#define vec(ll) vector<ll>

unordered_map<ll, ll> POS, SW, MX, MN;

ll extract(ordered_set(p(ll, ll)) S, ll a)
{
	ll t = 0;
	FOR(i, 1, a)
	{
		ll m = POS[i] - 1;
//		cout << m << ' ' << i << endl;
//		cout << S.order_of_key({m, i}) << endl;
		t += S.order_of_key({m, i});
		S.erase({m, i});
	}
	return t;
}

void Process()
{
	ll a;
	cin >> a;
	vec(ll) C(a);
	getVector(C);
	ordered_set(p(ll, ll)) S;
	FOR(i, 0, a - 1)
	{
		POS[C[i]] = i + 1;
		S.insert({i, C[i]});
	}
	ll mn = 1e18;
	ll mno = extract(S, a);
	if (mno < mn)
	{
		mn = mno;
	}
	vec(ll) ans = C;
	ll k = -1, q = -1;
	ll mxk = -1, mxq = -1;
	ordered_set(ll) P;
	FORD(i, a - 1, 0)
	{
		P.insert(C[i]);
		MN[i] = P.order_of_key(C[i]);
	}
	P.clear();
	FOR(i, 0, a - 1)
	{
		P.insert(-1 * C[i]);
		MX[i] = P.order_of_key(-1 * C[i]);
	}
	FOR(i, 0, a - 1)
	{
		if (MX[i] > mxk)
		{
			k = i;
			mxk = MX[i];
		}
		if (MN[i] > mxq)
		{
			q = i;
			mxq = MN[i];
		}
	}
	ll i = k, j = q;
	S.erase({i, C[i]});
	S.erase({j, C[j]});
	S.insert({j, C[i]});
	S.insert({i, C[j]});
	swap(POS[C[i]], POS[C[j]]);
	mno = extract(S, a) + 1;
	if (mno < mn)
	{
		ans = C;
		swap(ans[i], ans[j]);
		mn = mno;
	}
	swap(POS[C[i]], POS[C[j]]);
	S.insert({i, C[i]});
	S.insert({j, C[j]});
	S.erase({j, C[i]});
	S.erase({i, C[j]});
//	cout << k << ' ' << q << endl;
//	printVector(MN);
//	cout << endl;
//	printVector(ans);
//	cout << endl;
	cout << mn << endl;
}

signed main() 
{
	faster();
//	Begin()
//	{
		Process();
//	}
}

//  Geometric art by Daniel yuan
//  Redraw by Nguyen Thanh Chau
/*   
                ________
               /        \
              / /      \ \
     ________/ /        \ \________
    /        \            /        \ 
   / /      \ \  ______  / /      \ \
  / /        \ \________/ /        \ \
  \            /        \            /
   \  ______  / /      \ \  ______  /	
    \________/ /        \ \________/
    /        \            /        \
   / /      \ \  ______  / /      \ \   
  / /        \ \________/ /        \ \
  \            /        \            /    
   \  ______  / /      \ \  ______  /    
    \________/ /        \ \________/  
             \            /        
              \  ______  /
               \________/   	
     
    
*/
////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                               Coded by thanhchauns2                                //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////
