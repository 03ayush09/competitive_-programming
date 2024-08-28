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

// ll in accumulate 0LL


//example input for graph first line contains n , m;
// n are number of vertices or nodes && m is no. of edges and after n&m ;
// input is followed by m lines describing the graph and connected vertices
// if it is said that that it is undirectional  1 2 is given we can assume 2 1 is also connected

//n m followed by  m lines of description/configuration
// 6 9
// 1 3
// 1 5
// 3 5
// 3 4
// 3 6
// 3 2
// 2 6
// 2 4
// 5 6


//n m followed by  m lines of description/configuration and 3rd col represents weights here
// 6 9
// 1 3 4
// 1 5 3
// 3 5 2
// 3 4 7
// 3 6 8
// 3 2 9
// 2 6 1
// 2 4 2
// 5 6 3




void solve()
{
	// here input in graph1 represents input taken in adajacency matrix;
	// here input in graph2 represents input taken in adajacency list;
	int n, m;
	cin >> n >> m;
	int graph1[n + 1][n + 1] = {0};
	vector<vector<int>> graph2(n + 1);

	f(i, m, 0) {
		int v1, v2 , wt ;
		cin >> v1 >> v2 /*>>wt*/; //if wt included use wt
		// Adjacency matrix
		// in this representation space complexity is of size is O(n^2);
		// for n=10^6 not possible
		// so comes adjacency list
		graph1[v1][v2] = 1; // simple in case of Adj matrix we can do graph1[v1][v2] =  wt
		graph1[v2][v1] = 1; // if unidirectional

//      Adjacency list space use O(v+e)
		graph2[v1].push_back(v2);
		graph2[v2].push_back(v1);
	}


	/// IN CASE OF WEIGHTED GRAPHS ADJ LIST WILL REQUIRE vector<vector<pair<int,int>>>graph3(n+1);

	int v, e;
	cin >> v >> e;
	vector<vector<pair<int, int>>> graph3(v + 1);
	f(i, e, 0) {
		int n1, n2, wt;
		cin >> n1 >> n2 >> wt;
		graph3[n1].push_back({n2, wt});
		graph3[n2].push_back({n1, wt});
	}


	//ADVANATAGES OF ADJ MATRIX
	// question if i,j are connected or not or whats their weight ??
	// ADJ matrix can return ans in O(1) complexity;
	// if(a[i][j]==1) return true;
	// for weight direct we can output graph1[i][j];

	// BUT  IN CASE OF ADJ LIST // to check connection O(n) loop
	// TO CHECK IF i-->j
	// for ( auto child : graph2[i]) {
	// 	if(child == j) return true;
	// }

	// for getting wt in ADJ LIST
	// for(auto child : graph3[i]){
	// 	if(child.ff == j) wt = child.ss;
	// }
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
