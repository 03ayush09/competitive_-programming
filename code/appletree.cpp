#include <bits/stdc++.h>
using namespace std;
#define   ff first
#define   ss second
#define   ll long long int
#define   ull unsigned long long int
#define   meow(a) a.erase(unique(a.begin(),a.end()),a.end());
#define   all(a) a.begin(),a.end()
#define   nl '\n'
#define   cy cout<<"YES"<< nl
#define   cn cout<<"NO"<< endl
#define   mod 1000000007
#define   f(i,n,x) for(int i=x;i<n;++i)
#define   fr(j,n,x) for(int j=n ;j>=x;--j)
#define   debug(x) cerr << (#x) << " is " << (x) << endl

void printvec(vector<ll> &b) {for (auto  it : b) cout << it << " ";}
void printmp(map<string, int> &mp) {for (auto  it = mp.begin(); it != mp.end(); it++) cout << it->ff << " " << it->ss << endl;}


// https://codeforces.com/contest/1843/problem/D
// countinf leaf nodes prob

void solve()
{
	ll n;
	cin >> n;
	vector<vector<ll>> adj(n + 1);
	vector<ll> leaf(n + 1);
	f(i, n - 1, 0) {
		ll x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	function<void(int, int)> dfs = [&](int vtx, int par) ->void{
		if (adj[vtx].size() == 1 && vtx != 1) {
			leaf[vtx] = 1;
			return;
		}
		for ( auto child : adj[vtx]) {
			if (child != par) {
				dfs(child , vtx);
				leaf[vtx] += leaf[child];
			}
		}
	} ;

	dfs(1, 0);
	ll q;
	cin >> q;
	while (q--) {
		ll a, b;
		cin >> a >> b;
		cout << leaf[b] * leaf[a] << nl;
	}

}


int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll test = 1 ,  C = 1;
	cin >> test;
	f(i, test, 0)
	{
		//cout<<"Case #"<<C<<": ";
		solve();
		//C++;
	}
	return 0;
}
