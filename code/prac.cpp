#include <bits/stdc++.h>
#define   ff first
#define   ss second
#define   int long long int
#define   all(a) a.begin(),a.end()
#define   nl '\n'
#define   f(i,a,b) for(int i=a;i<b;i++)
#define   fr(i,a,b) for(int i=a;i>=b;i--)
#define   cy cout<<"YES"<< nl
#define   cn cout<<"NO"<<  nl
#define   cnl cout << nl;
#define   mod 1000000007
#ifndef   ONLINE_JUDGE
#define   debug(x) cerr << #x << " is " << x << endl;
#else
#define   debug(...);
#endif

using namespace std;

int m_mod(int x, int y) { return ((x % mod) * (y % mod)) % mod; }
int mpow(int x, int y) { if (y == 0)return 1; int temp = mpow(x, y >> 1); temp = m_mod(temp, temp); if (y & 1)return m_mod(temp, x); return temp; }
void printvec(vector<int> &b) {for (auto  it : b) cout << it << " ";}
bool cmp(pair<int, int>&a , pair<int, int>&b) {if (a.first != b.first)return (a.first >= b.first); else return (a.second <= b.second);}
bool isprime(int n) {if (n < 2) return 0; if (n == 2)return 1; f(i, 2, sqrt(n) + 1) if (n % i == 0) return 0 ; return 1;}

#define   bankai ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);


void solve()
{

  int n ;
  cin >> n;
  vector<int>v(n);
  f(i, 0, n) cin >> v[i];
  int x = v.back();
  v.pop_back();
  int y = *max_element(all(v));
  x += y;
  cout << x << nl;
}


signed main() {
  bankai;

  int _ = 1 ;
  cin >> _;

  f(i, 0, _) solve();
  return 0;
}
