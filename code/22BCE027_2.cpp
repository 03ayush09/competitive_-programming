#include <bits/stdc++.h>
#define   ff first
#define   ss second
#define   int long long int
#define   all(a) a.begin(),a.end()
#define   nl '\n'
#define   f(i,a,b) for(int i=a;i<b;i++)
#define   cy cout<<"YES"<< nl
#define   cn cout<<"NO"<<  nl
#define   cnl cout << nl;

using namespace std;

#define   bankai ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);


void solve()
{

    int n;
    cin >> n;
    vector<pair<int, int>>vp;
    f(i, 0, n) {
        int x;
        cin >> x;
        vp.push_back({x, i});
    }
    sort(all(vp));

    /*  dekh ye step ke baad apna vector aesa hojayega
    1 2
    2 1
    3 0

      */

    // f(i, 0, n) cout << vp[i].ff << " " << vp[i].ss << nl;

    f(i, 0, n) {
        if (vp[i].ss == i) {
            // if any index of the orginal array matched with the array of shortest permutation which is sorted array
            // so we will swap it with next element
            //but for last element it will be excepttion and we will swap it with previous element

            if (i != n - 1)swap(vp[i] , vp[i + 1]);
            else swap(vp[i] , vp[i - 1]);

        }
    }

    f(i, 0, n) {
        cout << vp[i].ff << " ";
    }
    cnl;


}


int32_t main() {
    bankai;

    int _ = 1 ;
    //cin>>_;

    f(i, 0, _) solve();
    return 0;
}
