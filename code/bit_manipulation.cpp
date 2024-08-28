#include <bits/stdc++.h>
using namespace std;
#define   ff first
#define   ss second
#define   int  int
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
void printbinary(int n) {for (int i = 15 ; i >= 0 ; i--) cout << ((n >> i) & 1) ;}

void solve()
{
	//************************BIT_MANIPULATION*******************************//

	// last bit of odd number are 1 as all other are in power of 2 so  if 2^0 is set so it means odd number;
	// to check if a number is odd do (n&1) if true number is odd else even;
	cout << "set bit of odd number :" << int(3 & 1) << nl;

	// if want a number in power of 2 as binary numbers are based on powers of 2 so we can left shift 1 in way we want
	// for 2^1(1<<1) for 2^2(1<<2) for 2^3(1<<3) /// 1<<n == pow(2,n);

	// maximun number of bit in signed int is 32 bit so greatest number will (1LL<<31)-1 && unsigned int has (1LL<<32)-1
	cout << "Pow(2,3) : " << int(1 << 3) << nl;

	// ______Terminologies_______

	// for eg : MSB(Nth bit most significant bit)-->(101001001001)<--LSB(0th bit least significant bit)
	// set bit means bit is 1 ans unset means bit is 0

	//Checking if (i)th bit of a number(n) is set or not we a number whose only ith bit is set and do & operation
	// ---> n&(1<<i)
	cout << "Checking 1st bit of 5 : " << int(5 & int(1 << 1)) << nl;

	// if we subtract 1 - pow(2,n) :: we get a number(n-1) whose all bits are set

	// to set a specific ith bit we can do | or operation with a number whose only ith bit is set
	cout << "setting 5's 1st bit to set bit : " << int( 5 | int(1 << 1)) << nl;

	//if we want to unset a bit we need a number whose all bits are set and ith bit is unset and so & with it
	// number whose all bits are set and ith bit notset is equal to not(whose only ith bit is set and all other unset)
	// n&(~(1<<i));
	cout << "unsetting 5's 0th bit : " << int(5 & int(~(1 << 0))) << nl;


	// form to toggle specific ith  bit means setting a bit to 0 or 1
	// we need a bit whose only ith bit is set ie(1<<i) // xor acts as a toggle operator
	// n^(1<<i)
	cout << "toggled 1st bit of 5 : " << int(5 ^ int(1 << 1)) << nl;

	//to print binary of a number
	int x = 27;
	cout << "Binary of 27 : ";
	for (int i = 15 ; i >= 0 ; i--) cout << ((x >> i) & 1) ;
	cout << nl;

// to check count of set bits
	int c = 0 , a = 27;
	for ( int i = 31 ;  i >= 0 ; i--) {
		if (a & (1 << i)) c++;
	}
	cout << "count of set bits in 27 : " << c << nl;
	cout << "count of set bits in 27 (inbuilt func): " << __builtin_popcount(a) << nl; //only for int32
// for ll
	long long f = (1LL << 35) - 1;
	cout << "count of set bits in LL(inbuilt func): " << __builtin_popcountll(f) << nl;

//__________TRICKS OF BIT MANIPULATION____________//

//odd even check done

// divide by 2 using bits n>>1 right shift by 1
	cout << "5 divide by 2 : " << int(5 >> 1) << nl;

// multiply by 2 we left shift n  by 1 n<<1
	cout << "5 * 2 : " << int(5 << 1) << nl;

// uppercase to lowercase using bits
// in uppercase bit next to msb is not set
// but in lower case but next to msb is set which is 5th bit
	char j = 'A';
	j = j ^ (1 << 5);
	cout << j << nl;
// lets use char(1<<5) which is acutually a ' ' single quotes imp space
	char g = 'd';
	g = g ^' ';
	cout << g << nl;

//how to clear "i" lbs's
	a = 59;
	printbinary(a);
	cout << nl;
	printbinary(a & (~((1 << 4) - 1))); // (a & ~((1<<i+1)-1)));
// clearing  msbs till 3rd bit
	cout << nl;
	printbinary(a & ((1 << 4) - 1)); // (a & ((1>> i+1)-1));


// power of 2 check we do n&(n-1);
	cout << "power2 chk : " << int(10 & 9) << nl;
	cout << "power2 chk : " << int(8 & 7) << nl;
	cout << "power2 chk : " << int(32 & 31) << nl;
// if n&(n-1) == 0 cy;
// simple logic see
// if power of 2 setbit count == 1
//                     000010000
// so n-1 bits will be 000001111
// so their and& should be 0

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
