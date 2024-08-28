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
#define   cn cout<<"NO"<<  nl
#define   mod 1000000007
#define   f(i,n,x) for(int i=x;i<n;++i)
#define   fr(j,n,x) for(int j=n ;j>=x;--j)
#define   debug(x) cerr << (#x) << " is " << (x) << endl

void printvec(vector<ll> &b) {for (auto  it : b) cout << it << " ";}
void printmp(map<string, int> &mp) {for (auto  it = mp.begin(); it != mp.end(); it++) cout << it->ff << " " << it->ss << endl;}

vector<vector<int>> subsets;

void generate(int i , vector<int>&subset, vector<int>&num) {
    if (i == num.size()) {
        subsets.push_back(subset);
        return;
    }
//not considering ith element
    generate(i + 1, subset, num);
// considering ith element
    subset.push_back(num[i]);
    generate(i + 1, subset, num);
    subset.pop_back();// backtracking step

}


void solve()
{
    int n;
    cin >> n;
    vector<int>v(n), empty;
    f(i, n, 0)cin >> v[i];
    generate(0, empty, v);
    for (auto it : subsets) {
        for ( auto i : it) {
            cout << i << " ";
        }
        cout << nl;
    }
    // debug(v.size());

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
