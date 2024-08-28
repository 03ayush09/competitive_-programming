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
void printmp(unordered_map<int, int> &mp) {for (auto  it = mp.begin(); it != mp.end(); it++) cout << it->ff << " " << it->ss << endl;}


const int N = 10e5 + 10;
vector<vector<ll>> adj(N);
vector<bool> vis(N);
vector<vector<int>> cc;
vector<int> curr_cc;

unordered_map<int , int>mp;
void dfs( int vtx ) {
    vis[vtx] = true;
    curr_cc.push_back(vtx);
    mp[vtx]++;
    for (auto child : adj[vtx]) {
        if (vis[child]) continue;
        dfs(child);
    }
}

//https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/ question link

void solve()
{
    int n, m;
    cin >> n >> m;
    f(i, m, 0) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int c  = 0;

    for (int i = 1 ; i < n + 1 ; i++) {
        if (mp[i] == 0) {
            curr_cc.clear();
            c++, dfs(i);
            cc.push_back(curr_cc);

        }
    }

    //printmp(mp);
    //debug(chk.size());
    cout << cc.size() << nl;
    for (auto it : cc) {
        for (auto i : it) {
            cout << i << " ";
        }
        cout << nl;
    }
    debug(c);



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
