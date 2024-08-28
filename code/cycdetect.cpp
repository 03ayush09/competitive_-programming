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


const int N  = 10e5 + 10;
vector<vector<ll>> adj(N);
vector<bool> vis(N);

bool dfs(int vtx , int par) {
	//int cur_par = vtx;
	vis[vtx] = true;
	bool isloop = false;

	for (auto child : adj[vtx]) {
		if (vis[child] && child == par) continue;
		if (vis[child]) return true;
		isloop != dfs(child, vtx);
	}
	return isloop;
}

bool solve()
{
	int n, m;
	cin >> n >> m;
	f(i, m, 0) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	return dfs(1, 1);
	//cn;

}


int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll test = 1 ,  C = 1;
	//cin>>test;
	f(i, test, 0)
	{
		//cout<<"Case #"<<C<<": ";
		cout << solve() << nl;
		//C++;
	}
	return 0;
}
