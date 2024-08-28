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

// question link :- https://leetcode.com/problems/flood-fill/

//sample input
// 3 3 0 0 2
// 1 1 1
// 1 1 0
// 1 0 1

void dfs(int i , int j , vector<vector<int>>&image , int nwcl , int incl) {
	int n = image.size();
	int m = image[0].size();
	if (i < 0 || j < 0) return;
	if (i >= n || j >= m) return;

	if (image[i][j] != incl) return; //invalid edge

	image[i][j] = nwcl;

	dfs(i - 1, j, image, nwcl , incl);
	dfs(i + 1, j, image, nwcl , incl);
	dfs(i, j - 1, image, nwcl , incl);
	dfs(i, j + 1, image, nwcl , incl);
	return;
}


vector<vector<int>> floodFill(vector<vector<int>>&image, int sr, int sc, int color) {
	int incl = image[sr][sc];
	dfs(sr, sc, image, color, incl);
	return image;
}

int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll test = 1 ,  C = 1;
	//cin>>test;
	f(i, test, 0)
	{

		int n, m, sr, sc, cl ;
		cin >> n >> m >> sr >> sc >> cl;
		vector<vector<int>> vp;
		f(i, n, 0) {
			vector<int> y;
			f(i, m, 0) {
				int x;
				cin >> x;
				y.push_back(x);
			}
			vp.push_back(y);
		}

		vector<vector<int>> b = floodFill(vp, sr, sc, cl);

		for (auto it : b ) {
			for (auto i : it) {
				cout << i << " ";
			}
			cout << nl;
		}
		//cout<<"Case #"<<C<<": ";

		//C++;
	}
	return 0;
}
