#include <bits/stdc++.h>
#define   ff first
#define   ss second
typedef   long long int ll;
typedef   unsigned long long ull;
#define   meow(a) a.erase(unique(a.begin(),a.end()),a.end());
#define   all(a) a.begin(),a.end()
#define   nl '\n'
#define   f(i,a,b) for(ll i=a;i<b;i++)
#define   fr(i,a,b) for(ll i=a;i>=b;i--)
#define   cy cout<<"YES"<< nl
#define   cn cout<<"NO"<<  nl
#define   mod 1000000007
#define   bankai ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef   ONLINE_JUDGE
#define   debugagi(x) cerr << #x << " is " << x << endl;
#else
#define   debug(...) 8
#endif

using namespace std;

void printvec(vector<ll> &b) {for (auto  it : b) cout << it << " ";}
ll m_mod(ll x, ll y) { return ((x % mod) * (y % mod)) % mod; }
ll mpow(ll x, ll y) { if (y == 0)return 1; int temp = mpow(x, y / 2); temp = m_mod(temp, temp); if (y % 2)return m_mod(temp, x); return temp; }
bool cmp(pair<int, int>&a , pair<int, int>&b) {if (a.first != b.first)return (a.first >= b.first); else return (a.second <= b.second);}

//input
/*8
2 3 1
9 1 7
9 8 3
2 4 9
1 7 2
1 8 1
4 3 1
3 7 5 */

// link :-https://www.hackerrank.com/challenges/fibonacci-finding-easy/problem
int T[2][2];
int d[2][2];

void matmultiply(int I[][2] , int A[][2] , int dim) {
	int res[dim + 1][dim + 1];
	f(i, 0, dim) {
		f(j, 0, dim) {
			res[i][j] = 0;
			f(k, 0, dim) {
				ll x = m_mod(I[i][k], A[k][j]);
				res[i][j] = (res[i][j] % mod + x % mod) % mod;
			}
		}
	}
	f(i, 0, dim) f(j, 0, dim) I[i][j] = res[i][j];
}

void matpow(int A[][2], int dim , int n) {
	/*  f(i, 0, n) matmultiply(I, A, dim);*/ //naive approach
	while (n) {
		if (n & 1) matmultiply(d, A, dim), n--;
		else matmultiply(A, A, dim) , n /= 2;
	}

	f(i, 0, dim)f(j, 0, dim) A[i][j] = d[i][j];
}

void AP()
{
	T[0][0] = 0 , T[0][1] = T[1][0] = T[1][1] = 1;
	d[0][0] = d[1][1] = 1, d[1][0] = d[0][1] = 0;
	int dim = 2;
	int a[2][2];
	cin >> a[0][0] , cin >> a[0][1];
	int n; cin >> n;
	////cout << T[0][0];
	if (n < 2) {
		cout << a[0][n] << nl;
		return;
	}
	n--;
	if (n > 1)matpow(T, dim, n);
	matmultiply(a, T, dim );
	cout << a[0][1] << nl;
}


signed main() {
	bankai;
	ll test = 1 ;
	cin >> test;
	f(i, 0, test) AP();
	return 0;
}
