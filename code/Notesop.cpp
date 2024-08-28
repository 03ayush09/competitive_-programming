#include <bits/stdc++.h>
using namespace std;
#define   ll long long
#define   ull unsigned long long int
#define   all(a) a.begin(),a.end()
#define   ff first
#define   ss second
#define   nl '\n'
#define   cy cout<<"YES"<< nl
#define   cn cout<<"NO"<< nl
#define   mod 1000000007
#define   f(i,n,x) for(int i=x;i<n;++i)
#define   fr(j,n,x) for(int j =n ;j>=x;--j)
#define   bankai ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#define   vec_max_index(v,b) upper_bound(all(v),b) - v.begin() - 1
#define   vec_min_index(v,b) lower_bound(all(v),b) - v.begin()
#define   min3(a, b, c) min(a, min(b, c))
#define   min4(a, b, c, d) min(a, min(b, min(c, d)))
#define   max3(a, b, c) max(a, max(b, c))
#define   max4(a, b, c, d) max(a, max(b, max(c, d)))

void printvec(vector<int> &b) {for (auto  it : b) cout << it << " ";}
void printmp(map<string, int> &mp) {for (auto  it = mp.begin(); it != mp.end(); it++) cout << it->ff << " " << it->ss << endl;}
//const int N = 1e7+10;
//ll a[N];

// https://codeforces.com/contest/166/submission/210697556 problem solved using comp func

//#comparator function
bool cmp(pair<int, string>a , pair<int, string>b) {
    if (a.first != b.first) {
        if (a.first > b.first ) return true;
        return false;
    }
    else {
        if (a.second < b.second) return true;
        return false;
    }
}

ll binarysearch(vector<ll>&v , ll x, ll lo , ll hi) {
    ll mid = lo + (hi - lo) / 2;
    if (v[mid] == x) return mid;
    else if (v[mid] < x) return binarysearch(v, x, mid + 1, hi);
    else if (v[mid] > x) return binarysearch(v, x, lo, mid - 1);
    return -1;
}


void nthroot(double x) {
    double eps = 1e-6;
    double hi = x , lo = 1, mid;

    while ((hi - lo) > eps) {
        mid = (hi + lo) / 2;
        if (mid * mid < x) lo = mid;
        else hi = mid;
    }
    cout << lo << nl;
}


void solve()
{
    /*
    int n;
    cin >> n;
    vector<pair<int, string>>vp;
    f(i, n, 0) {
        string s;
        cin >> s;
        int x;
        cin >> x;
        vp.push_back({x, s});

    }
    sort(all(vp), cmp);
    for (auto it : vp) {
        cout << it.ss << " " << it.ff << nl;
    }




    //////upper bound lower bound ///////////////
    */
    // int n ;
    // cin >> n;
    // vector<int> v;
    // set<int>s;
    // std::map<int, int> mp;
    // f(i, n, 0) {
    //     int x;
    //     cin >> x;
    //     v.push_back(x);
    //     s.insert(x);
    //     mp[x]++;
    // }
    // sort(all(v));
    // printvec(v);
    // cout << nl;
    // auto it = upper_bound(all(v), 10) - v.begin(); // to get array min index
    // auto i = s.upper_bound(10);
    // auto itt  = mp.upper_bound(11);
    // auto ap = vec_min_index(v, 10);
    // cout << ap << nl;






    //////////lambda function//////
    auto square = [](int i) {return i * i;};
    cout << square(2);



    // function<void(int, int)> dfs = [&](int x, int y) -> void {
    //     if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y] || adj[x][y] == 0) {
    //         return;
    //     }
    //     vis[x][y] = 1;
    //     sum += adj[x][y];
    //     dfs(x - 1, y);
    //     dfs(x + 1, y);
    //     dfs(x, y - 1);
    //     dfs(x, y + 1);
    // };

    // refer lakesdfs.cpp file

    // function to count numbers greater than or equal to 5
    //int count_5 = count_if(v.begin(), v.end(), [](int a){return (a >= 5);});
    vector<int>  v = {1, 2, 3, 4, 5};
    auto rem = [](int i , int j) { return j % i;};

    for (int i = 0 ; i < 5; i++) {
        rem(i, i + 1);
    }
}


int main() {

    bankai;
    ll test = 1;
    //cin>>test;
    f(i, test, 0)
    {
        solve();
    }
    return 0;
}
