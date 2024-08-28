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

void printvec(vector<int> &b) {for (auto  it : b) cout << it << " ";}
void printmp(map<string, int> &mp) {for (auto  it = mp.begin(); it != mp.end(); it++) cout << it->ff << " " << it->ss << endl;}


// https://codeforces.com/contest/1829/problem/E
void solve()
{

	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>(m, 0)), vis(n, vector<int>(m, 0));
	f(i, n, 0) f(j, m, 0) cin >> adj[i][j];
	int sum = 0 ;
	function<void(int, int)> dfs = [&](int x, int y) -> void {
		if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y] || adj[x][y] == 0) {
			return;
		}
		vis[x][y] = 1;
		sum += adj[x][y];
		dfs(x - 1, y);
		dfs(x + 1, y);
		dfs(x, y - 1);
		dfs(x, y + 1);
	};

	int c = 0;
	f(i, n, 0) {
		f(j, m, 0) {
			if (vis[i][j] == 0)dfs(i, j), c++;
		}
	}
	cout << c << nl;


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
