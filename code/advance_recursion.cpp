#include <bits/stdc++.h>
using namespace std;
#define   ff first
#define   ss second
#define   int long long int
#define   ull unsigned long long int
#define   meow(a) a.erase(unique(a.begin(),a.end()),a.end());
#define   all(a) a.begin(),a.end()
#define   nl '\n'
#define   cy cout<<"YES"<< nl
#define   cn cout<<"NO"<< endl
#define   mod 1000000007
#define   f(i,n,x) for(int i=x;i<n;++i)
#define   fr(j,n,x) for(int j =n ;j>=x;--j)
#define   vec_max_index(v,b) upper_bound(all(v),b) - v.begin() - 1
#define   vec_min_index(v,b) lower_bound(all(v),b) - v.begin()
#define   debug(x) cerr << (#x) << " is " << (x) << endl

void printvec(vector<string> &b) {for (auto  it : b) cout << it << nl;}
void printmp(map<string, int> &mp) {for (auto  it = mp.begin(); it != mp.end(); it++) cout << it->ff << " " << it->ss << endl;}

vector<string> v;

//k-th symbol in grammer question on leetcode
// need improvisation // input n,k, initially s="0" , do n--;
// void grammer(string &s, int n , int k) {
// 	//debug(s);
// 	if (n == 0) {
// 		cout << s[k - 1];
// 		return;
// 	}
// 	string z = "";
// 	for (auto it : s) {
// 		if (it == '0') z.append("01");
// 		else z.append("10");
// 	}
// 	s = z;
// 	grammer(s, n - 1, k);
// }


//question generate parenthesis on leetcode
void generate(string &s, int op , int cl ) {
	if (op == 0 && cl == 0) {
		v.push_back(s);
		return;
	}
	if (op > 0 ) {
		s.push_back('(');
		//cout << s << nl;
		generate(s , op - 1 , cl);
		s.pop_back();
	}
	//cout << s << nl;
	if (cl > 0) {
		if (op < cl) {
			s.push_back(')');
			generate(s, op, cl - 1);
			s.pop_back();
		}
	}
}

void solve()
{
	int n;
	cin >> n;
	string s = "";
	generate(s, n, n);
	printvec(v);


}


int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test = 1 ; int C = 1;
	//cin>>test;
	f(i, test, 0)
	{
		//cout<<"Case #"<<C<<": ";
		solve();
		//C++;
	}
	return 0;
}
