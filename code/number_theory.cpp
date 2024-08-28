////AUTHOR - AyushPatel_03

#include <bits/stdc++.h>
#define   ff first
#define   ss second
typedef   long long int ll;
typedef   unsigned long long ull;
#define   meow(a) a.erase(unique(a.begin(),a.end()),a.end());
#define   all(a) a.begin(),a.end()
#define   nl '\n'
#define   f(i,a,b) for(ll i=a;i<b;i++)
#define   fr(i,a,b) for(ll i=a;i>=b;i--)
#define   cy cout<<"YES"<< nl
#define   cn cout<<"NO"<<  nl
#define   bankai ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef   ONLINE_JUDGE
#define   debug(x) cerr << #x << " is " << x << endl;
#else
#define   debug(...) 8
#endif

// SUM of First K odd integers is K^2
// 1 3 5 7 11
// 1 4 9 16 25
using namespace std;

const int mod = (int)1e9 + 7;
void printvec(vector<ll> &b) {for (auto  it : b) cout << it << " ";}
ll m_mod(ll x, ll y) { return ((x % mod) * (y % mod)) % mod; }
ll mpow(ll x, ll y) { if (y == 0)return 1; int temp = mpow(x, y / 2); temp = m_mod(temp, temp); if (y % 2)return m_mod(temp, x); return temp; }
bool cmp(pair<int, int>&a , pair<int, int>&b) {if (a.first != b.first)return (a.first >= b.first); else return (a.second <= b.second);}

int nmod(int a) { return (a >= mod ? a % mod : a); }
int modfastexpo(int a, int b) { a = nmod(a); int res = 1; while (b) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b = b >> 1; } return res; }
int modadd(int a, int b) { a = nmod(a); b = nmod(b); int res = a + b; return (res >= mod ? res - mod : res); }
int modsub(int a, int b) { a = nmod(a); b = nmod(b); int res = a - b; return (res < 0 ? res + mod : res); }
int modmul(int a, int b) { a = nmod(a); b = nmod(b); int res = a * b; return (res >= mod ? res % mod : res); }
int moddiv(int a, int b) { b = modfastexpo(b, mod - 2); return modmul(a, b); }

int ar[101][101] , I[101][101];

void matmultiply(int I[][101] , int A[][101] , int dim) {
    int res[dim + 1][dim + 1];
    f(i, 0, dim) {
        f(j, 0, dim) {
            res[i][j] = 0;
            f(k, 0, dim) res[i][j] += I[i][k] * A[k][j];
        }
    }
    f(i, 0, dim) f(j, 0, dim) I[i][j] = res[i][j];
}

void matpower(int A[][101], int dim , int n) {
    f(i, 0, dim) f(j, 0, dim) {
        if (i == j) I[i][j] = 1;
        else I[i][j] = 0;
    }
    /*  f(i, 0, n) matmultiply(I, A, dim);*/ //naive approach
    while (n) {
        if (n & 1) matmultiply(I, A, dim), n--;
        else matmultiply(A, A, dim) , n /= 2;
    }

    f(i, 0, dim)f(j, 0, dim) A[i][j] = I[i][j];
}



void solve()
{


    //--> IMP FORMULAS <--
    /* (a+b)%M = ((a%M)+(b%M))%M;
       (a*b)%M = ((a%M)*(b%M))%M;
       (a-b)%M = ((a%M)-(b%M)+M)%M;
       (a/b)%M = ((a%M*(b^-1)%M)%M; */


    // -----> FACTORIAL <------
    //-->need to print factorial of n and n>=1 && n<=100
    /*  ull n;
        cin >> n;
        ull fact = 1;
        for (int i = 1; i <= n; i++) {
            fact = (fact * i) % mod;
        }
        cout << fact; */




    // -----> PRIME CHECK <----

    //-->to check for prime check only till sqrt(n);
    /*  ll n;
    cin >> n;
    ll k  = sqrt(n);
    f(i,2,k) {
        if (n == 1) cn;
        else {
            if (n % i == 0) {
                cn;
                return;
            }
        }
    }
    cy;
    */


    // ----> SIEVE OF ERATOSTHENES <-----

    // if asked to find prime numbers in range of some numbers then use sieve of eratosthenes
    // or can be used to mark elements prime not prime in certain range
    int n , m;
    cin >> n >> m;
    vector<bool> primevis(m, 1);  // consider all prime
    // variation of sieve  calculating highest prime(hp) & lowest prime of evry number LP;
    vector<int> lp(m), hp(m);
    unordered_map<int, int> primefactors; // storing prime factors using lp hp;
    primevis[0] = 0, primevis[1] = 0; // we know 0 and 1 not prime

    // main algo
    for (int i = 2 ; i * i <= m; i++) {
        if (primevis[i]) {
            hp[i] = lp[i] = i; // as for prime numbers itself they are lp and hp
            for (int j = i * i ; j <= m; j += i) { //j+=i so marking all multiples of prime as composite
                primevis[j] = 0;
                if (lp[j] == 0) lp[j] = i; //marked only once
                hp[j] = i; // updated every time ;
            }
        }
    } // mloglogm ka loop

    f(i, n, m + 1) {
        if (primevis[i]) cout  << i << ",";
    }



    // ------> PRIME FACTORISATION USING SIEVE <-----


    int num; // number to take factors off
    cin >> num;
    while (num > 1) {
        int primefac = lp[num];
        while (num % primefac == 0) {
            num /= primefac;
            primefactors[primefac]++;
        }
    }
    for (auto it : primefactors) {
        cout << it.ff << " " << it.ss << nl;
    }
    cout << endl;





    // ------> FINDING DIVISORS USING SIMILAR ALGO LIKE SIEVE <----------

    // we can get all divisors of a number by sieve just remove prime check
    /*   int y;
       cin >> y;
       vector<vector<int>> divisors(y);
       for (int i = 2 ; i < y; i++) {
           for (int j = i ; j < y; j += i) {
               divisors[j].push_back(i);
           }
       }
       for (auto it : divisors) {
           for (auto pr : it) {
               cout << pr << " ";
           }
           cout << nl;
       }

    */


    //----------->BINARY EXPONENTATION && MODULAR EXPONENTATION <--------

    /*function<ll(ll, ll)> mpow = [&](ll base, ll pw)->ll{
        ll res = 1;
        while (pw) {
            if (pw % 2) res *= base % mod , pw--;
            else base = ((base % mod) * (base % mod)) % mod, pw /= 2;
        }
        return res;
    };

    ll f = mpow(100, 10);
    cout << f << nl;*/




    // ---------> GCD EUCLID's METHOD <-----------

    //gcd(a-b, b) == gcd(a,b-a) == gcd(a,b)


    /*  function<ll(ll, ll)> gcd = [&](ll a, ll b) ->ll{
          if (a % b) return gcd(b, a % b);
          else return b;
      };
      ll f = gcd(12LL, 18LL);
      cout << f << nl;*/


    //----------> MATRIX EXPONENTATION<------------
    /*   int dim ; cin >> dim;
       int n; cin >> n;

       f(i, 0, dim)f(j, 0, dim) cin >> ar[i][j];
       matpower(ar, dim, n);
       debug(dim);
       f(i, 0, dim) {
           f(j, 0, dim) {
               cout << ar[i][j] << " ";
           }
           cout << nl;
       }*/


    //---------> RECURRENCE RELATION <------------
    /* FIB f(n) = f(n-1)+f(n-2); n>2;
    f(1)= 1;
    f(2)= 1;

    base cases
    as fib is dependent on prev k=2 cases here k is 2;
    */

    // [F1 F2] *[a b , c d] = [F2 F3];
    // [F1 F2] * [a b,c d]^n-1 = [Fn Fn-1];


}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll test = 1 ;
    //ll C = 1;
    //cin>>test;
    f(i, 0, test)
    {
        //cout<<"Case #"<<C<<": ";
        solve();
        //C++;
    }
    return 0;
}
