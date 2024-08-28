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



//sample input
// 6 9
// 1 3
// 1 5
// 3 5
// 3 4
// 3 6
// 3 2
// 2 6
// 4 6
// 5 6

// DECLARING ADJACENT LIST AND VISITED ARRAY AND ITS SIZE ;
const int N = 10e5 + 10;
vector<bool> vis(N); //visited array;
vector<vector<int>> adj(N);


// vtx ==  vertex
// four main sections of code in dfs function  denoted by //*
// any dfs can be solved using this 4 spaces //*
void dfs( int vtx) { // TC O(v+e)
	//*take action on vertex after entering the vertex
	vis[vtx] = true ;
	cout << vtx << nl;
	for (auto child : adj[vtx]) {
		//cout << "par" << vtx << " " << "child" << child << nl;
		if (vis[child]) continue;
		//* take action on child before entering the child node
		dfs(child);
		//*take action on child after exting the child node
	}
	//*take action on vertex before exiting the vertex
}

void solve()
{
	int n, m;
	cin >> n >> m;
	f(i, m, 0) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(5);
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
		solve();
		//C++;
	}
	return 0;
}
