// @Author: Mars_Coder
// @date: 01-Jan-24 1:53:10 AM +06
// https://projecteuler.net/problem=13

#define _USE_MATH_DEFINES
#undef _GLIBCXX_DEBUG

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


using lli = long long int;
using uInt = unsigned int;
using ulli = unsigned long long int;
using vi = vector<int>;
using vii = vector<lli>;
using vc = vector<char>;
using udouble = long double;
using vd = vector<double>;
using vs = vector<string>;
template<typename T> using vv = vector<vector<T>>;
template<typename T> using pq = priority_queue<T>;  // high prec., pq<T> p;
template<typename T> using pq_ = priority_queue<T, vector<T>, greater<T>>;  // dec. as: pq_<T> x;
template<typename T1, typename T2> using vp = vector<pair<T1, T2>>;  // vp<T1, T2> ..


/*---------- pbds -------------*/
// *find_by_order(x), order_of_key(x) + set/map fns
// ordered_set/map:
/*
	pbds<int, null_type, less<int>> uset; -> ordered_set
	pbds<int, null_type, greater<int>>  -> decr. order
	pbds<int, null_type, less_equal<int>> -> multi-set
	pbds<int, int, less<int>> -> ordered_map
	pbds<int, int, less_equal<int>> -> multi-map
	............

	!! ALERT !! (for using less_equals<key>)
    using less_equals<key> makes lower_bound works as upper_bound and vice-versa
    for erase use: any.erase(any.find_by_order(any.order_of_key(val)));
    don't use .find() because it will always return .end()
*/

template<typename key, typename val = null_type, typename cmp = less<key>> 
using pbds = tree<key, val, cmp, rb_tree_tag, tree_order_statistics_node_update>;

/*-----------------------------*/

#define ln                "\n" // no flush, oppos of endl
#define _flush            endl
#define stop_sync         ios::sync_with_stdio(false) // not to use c-style io
#define untie_ios         cin.tie(nullptr) // no flush
#define pb                push_back
#define ppb 	          pop_back
#define mp                make_pair
#define Fi(p)             get<0>(p)
#define Sc(p)             get<1>(p)
#define sz(x)             int ((x).size())
#define All(x)            (x).begin(), (x).end()
#define scanv(x)          for(auto &i: x) cin >> i
#define bin_sc(a, x)      binary_search(All(a), x) // 0/1
#define lbd(a, x)         lower_bound(All(a), x) // an iter.
#define ubd(a, x)         upper_bound(All(a), x) // an iter.
#define eq_seg(a, x)      equal_range(All(a), x) // a pair of lb, ub
#define minE(a)           (*min_element(All(a)))
#define maxE(a)           (*max_element(All(a)))
#define FIXED(x)          cout << fixed << setprecision(x)
#define mem(a, v)         memset(a, v, sizeof a) // 0,-1 for int, and all char
#define filla(a, n, v)    fill(a, a + n, v) // for arr.
#define fillv(a, v)       fill(All(a), v) // for vec.
#define _fillv(a, n, v)   fill_n(a.begin(), n, v)
#define glue(x, y)        x##y
#define msg(x)            cout << (#x) << ln
#define bug(x)            cout << (#x) << ": " << (x) << ln
#define printv(v)         cout << "[ ";for(auto j: v) cout << j << ' '; cout << "]" << ln
#define printvv(v)        cout << "["; for(auto i: v) {printv(i);} cout << "........]\n"
#define printm(m)         cout << "[\n";for(auto i: m) cout << Fi(i) << " -> " << Sc(i) << ln; cout << "...]\n"
#define prints(s)         cout << "{"; for(auto i: s) cout << i << ' '; cout << "}\n"
#define uceil(a, b)       ((a + b - 1) / (b))
#define unq_v(a)          a.resize(distance(a.begin(), unique(All(a)))) // for same valued consec. grp
#define mk_upper(s)       transform(s.begin(), s.end(), s.begin(), ::toupper)
#define mk_lower(s)       transform(s.begin(), s.end(), s.begin(), ::tolower)
#define valid(nx, ny)     (nx >= 1 && nx <= row && ny >= 1 && ny <= col)
#define dbug(args...)     {string s = #args;replace(All(s), ',', ' '); stringstream s2; s2 << s; vs ss;\
while(s2){string now;     s2 >> now; ss.pb(now);} debug(ss, args);} // string sucks :(, don't know why!


vector<int> dx = {1,-1,0,0,1,-1,-1,1}; // (4 ed. + 4 dia.)
vector<int> dy = {0,0,1,-1,1,1,-1,-1}; // first four are ed.

const string yms[]{"YES", "Yes", "yes"};
const string nms[]{"NO", "No", "no"};
const double PI = acos(-1.0L);
struct{const int i = (1e9) + 7; const lli l = (lli)(1e9) + 7ll;}MOD;
struct{const int i = INT_MAX; const lli l = LLONG_MAX;}inf;

bool isUp(char ch){locale loc; return isupper(ch, loc);}
void debug(vs s) {cout << "#------------------#\n";}
int ffs(int x){return __builtin_ffs(x);}  // 1 based idx from right of one
int ffs(lli x){return __builtin_ffsll(x);}
int clz(uInt x){return __builtin_clz(x);}  // leading zeros from left ....
int clz(ulli x){return __builtin_clzll(x);}
int ctz(uInt x){return __builtin_ctz(x);}  // trailing zeros from right ....
int ctz(ulli x){return __builtin_ctzll(x);}
int cto(uInt x){return __builtin_popcount(x);}  // no of 1 bit
int cto(ulli x){return __builtin_popcountll(x);}
int parity(uInt x){return __builtin_parity(x);}  // cto % 2
int parity(ulli x){return __builtin_parityll(x);}
auto pow2(uInt x){return (1u) << x;}  /* returning unsigned */
auto pow2(ulli x){return (1ull) << x;}  // x <= 63
lli binpow(lli a, lli b){lli ans = 1ll; while(b > 0){if(b & 1) ans *= a; a *= a; b >>= 1;} return ans;}
lli binpow(lli a, lli b, lli m){a %= m; lli ans = 1ll; while(b > 0){if(b & 1) ans = ans * a % m; a = a * a % m; b >>= 1;} return ans;}
lli NcR(lli n, lli r){lli x = 1ll, y = 1ll;if(n - r < r) r = n - r; while(r){x *= n;y *= r;
lli cm = gcd(x, y);x /= cm;y /= cm;--n;--r;}return x;}
lli lcm(lli a, lli b){ if(a > b) swap(a, b); return (a * (b / gcd(a, b)));}
lli NpR(lli n, lli r){lli x = 1ll;while(r){x *= n; --n;--r;}return x;}

template<typename type> type Nsum(type n){return (n * (n + 1)) / (type)2;}
template<typename type> type Round(type a, type b) {if(a < b) return 1; if(a % b) return 1 + a / b; return a / b;}
template<typename T, typename... param> void debug(vs ss, T a, param... args){
	cout << ss.front() << " = " << a << '\n'; ss.erase(ss.begin()); debug(ss, args...);
}


// array<T, n> a = {}

class BigInt{
    string digits;
	public:
 
    	//Constructors:
    	BigInt(unsigned long long n = 0);
    	BigInt(string &);
    	BigInt(const char *);
    	BigInt(BigInt &);
 		
    	//Helper Functions:
    	friend void divide_by_2(BigInt &a);
    	friend bool Null(const BigInt &);
    	friend int length(const BigInt &);
    	int operator[](const int)const;
 
               /* * * * Operator Overloading * * * */
 		
    	//Direct assignment
    	BigInt &operator=(const BigInt &);
    	
    	//Post/Pre - Incrementation
    	BigInt &operator++();
    	BigInt operator++(int temp);
    	BigInt &operator--();
    	BigInt operator--(int temp);
 
    	//Addition and Subtraction
    	friend BigInt &operator+=(BigInt &, const BigInt &);
    	friend BigInt operator+(const BigInt &, const BigInt &);
    	friend BigInt operator-(const BigInt &, const BigInt &);
    	friend BigInt &operator-=(BigInt &, const BigInt &);
 
    	//Comparison operators
    	friend bool operator==(const BigInt &, const BigInt &);
    	friend bool operator!=(const BigInt &, const BigInt &);
 
    	friend bool operator>(const BigInt &, const BigInt &);
    	friend bool operator>=(const BigInt &, const BigInt &);
    	friend bool operator<(const BigInt &, const BigInt &);
    	friend bool operator<=(const BigInt &, const BigInt &);
 
    	//Multiplication and Division
    	friend BigInt &operator*=(BigInt &, const BigInt &);
    	friend BigInt operator*(const BigInt &, const BigInt &);
    	friend BigInt &operator/=(BigInt &, const BigInt &);
    	friend BigInt operator/(const BigInt &, const BigInt &);
 
    	//Modulo
    	friend BigInt operator%(const BigInt &, const BigInt &);
    	friend BigInt &operator%=(BigInt &, const BigInt &);
 
    	//Power Function
    	friend BigInt &operator^=(BigInt &,const BigInt &);
    	friend BigInt operator^(BigInt &, const BigInt &);
     
    	//Square Root Function
    	friend BigInt sqrt(BigInt &a);
 
    	//Read and Write
    	friend ostream &operator<<(ostream &,const BigInt &);
    	friend istream &operator>>(istream &, BigInt &);
 
    	//Others
    	friend BigInt NthCatalan(int n);
    	friend BigInt NthFibonacci(int n);
    	friend BigInt Factorial(int n);
};

BigInt::BigInt(string & s){
    digits = "";
    int n = s.size();
    for (int i = n - 1; i >= 0;i--){
        if(!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}
BigInt::BigInt(unsigned long long nr){
    do{
        digits.push_back(nr % 10);
        nr /= 10;
    } while (nr);
}
BigInt::BigInt(const char *s){
    digits = "";
    for (int i = strlen(s) - 1; i >= 0;i--)
    {
        if(!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}
BigInt::BigInt(BigInt & a){
    digits = a.digits;
}
 
bool Null(const BigInt& a){
    if(a.digits.size() == 1 && a.digits[0] == 0)
        return true;
    return false;
}
int length(const BigInt & a){
    return a.digits.size();
}
int BigInt::operator[](const int index)const{
    if(digits.size() <= index || index < 0)
        throw("ERROR");
    return digits[index];
}
bool operator==(const BigInt &a, const BigInt &b){
    return a.digits == b.digits;
}
bool operator!=(const BigInt & a,const BigInt &b){
    return !(a == b);
}
bool operator<(const BigInt&a,const BigInt&b){
    int n = length(a), m = length(b);
    if(n != m)
        return n < m;
    while(n--)
        if(a.digits[n] != b.digits[n])
            return a.digits[n] < b.digits[n];
    return false;
}
bool operator>(const BigInt&a,const BigInt&b){
    return b < a;
}
bool operator>=(const BigInt&a,const BigInt&b){
    return !(a < b);
}
bool operator<=(const BigInt&a,const BigInt&b){
    return !(a > b);
}
 
BigInt &BigInt::operator=(const BigInt &a){
    digits = a.digits;
    return *this;
}
 
BigInt &BigInt::operator++(){
    int i, n = digits.size();
    for (i = 0; i < n && digits[i] == 9;i++)
        digits[i] = 0;
    if(i == n)
        digits.push_back(1);
    else
        digits[i]++;
    return *this;
}
BigInt BigInt::operator++(int temp){
    BigInt aux;
    aux = *this;
    ++(*this);
    return aux;
}
 
BigInt &BigInt::operator--(){
    if(digits[0] == 0 && digits.size() == 1)
        throw("UNDERFLOW");
    int i, n = digits.size();
    for (i = 0; digits[i] == 0 && i < n;i++)
        digits[i] = 9;
    digits[i]--;
    if(n > 1 && digits[n - 1] == 0)
        digits.pop_back();
    return *this;
}
BigInt BigInt::operator--(int temp){
    BigInt aux;
    aux = *this;
    --(*this);
    return aux;
}
 
BigInt &operator+=(BigInt &a,const BigInt& b){
    int t = 0, s, i;
    int n = length(a), m = length(b);
    if(m > n)
        a.digits.append(m - n, 0);
    n = length(a);
    for (i = 0; i < n;i++){
        if(i < m)
            s = (a.digits[i] + b.digits[i]) + t;
        else
            s = a.digits[i] + t;
        t = s / 10;
        a.digits[i] = (s % 10);
    }
    if(t)
        a.digits.push_back(t);
    return a;
}
BigInt operator+(const BigInt &a, const BigInt &b){
    BigInt temp;
    temp = a;
    temp += b;
    return temp;
}
 
BigInt &operator-=(BigInt&a,const BigInt &b){
    if(a < b)
        throw("UNDERFLOW");
    int n = length(a), m = length(b);
    int i, t = 0, s;
    for (i = 0; i < n;i++){
        if(i < m)
            s = a.digits[i] - b.digits[i]+ t;
        else
            s = a.digits[i]+ t;
        if(s < 0)
            s += 10,
            t = -1;
        else
            t = 0;
        a.digits[i] = s;
    }
    while(n > 1 && a.digits[n - 1] == 0)
        a.digits.pop_back(),
        n--;
    return a;
}
BigInt operator-(const BigInt& a,const BigInt&b){
    BigInt temp;
    temp = a;
    temp -= b;
    return temp;
}
 
BigInt &operator*=(BigInt &a, const BigInt &b)
{
    if(Null(a) || Null(b)){
        a = BigInt();
        return a;
    }
    int n = a.digits.size(), m = b.digits.size();
    vector<int> v(n + m, 0);
    for (int i = 0; i < n;i++)
        for (int j = 0; j < m;j++){
            v[i + j] += (a.digits[i] ) * (b.digits[j]);
        }
    n += m;
    a.digits.resize(v.size());
    for (int s, i = 0, t = 0; i < n; i++)
    {
        s = t + v[i];
        v[i] = s % 10;
        t = s / 10;
        a.digits[i] = v[i] ;
    }
    for (int i = n - 1; i >= 1 && !v[i];i--)
            a.digits.pop_back();
    return a;
}
BigInt operator*(const BigInt&a,const BigInt&b){
    BigInt temp;
    temp = a;
    temp *= b;
    return temp;
}
 
BigInt &operator/=(BigInt& a,const BigInt &b){
    if(Null(b))
        throw("Arithmetic Error: Division By 0");
    if(a < b){
        a = BigInt();
        return a;
    }
    if(a == b){
        a = BigInt(1);
        return a;
    }
    int i, lgcat = 0, cc;
    int n = length(a), m = length(b);
    vector<int> cat(n, 0);
    BigInt t;
    for (i = n - 1; t * 10 + a.digits[i]  < b;i--){
        t *= 10;
        t += a.digits[i] ;
    }
    for (; i >= 0; i--){
        t = t * 10 + a.digits[i];
        for (cc = 9; cc * b > t;cc--);
        t -= cc * b;
        cat[lgcat++] = cc;
    }
    a.digits.resize(cat.size());
    for (i = 0; i < lgcat;i++)
        a.digits[i] = cat[lgcat - i - 1];
    a.digits.resize(lgcat);
    return a;
}
BigInt operator/(const BigInt &a,const BigInt &b){
    BigInt temp;
    temp = a;
    temp /= b;
    return temp;
}
 
BigInt &operator%=(BigInt& a,const BigInt &b){
    if(Null(b))
        throw("Arithmetic Error: Division By 0");
    if(a < b){
        return a;
    }
    if(a == b){
        a = BigInt();
        return a;
    }
    int i, lgcat = 0, cc;
    int n = length(a), m = length(b);
    vector<int> cat(n, 0);
    BigInt t;
    for (i = n - 1; t * 10 + a.digits[i] < b;i--){
        t *= 10;
        t += a.digits[i];
    }
    for (; i >= 0; i--){
        t = t * 10 + a.digits[i];
        for (cc = 9; cc * b > t;cc--);
        t -= cc * b;
        cat[lgcat++] = cc;
    }
    a = t;
    return a;
}
BigInt operator%(const BigInt &a,const BigInt &b){
    BigInt temp;
    temp = a;
    temp %= b;
    return temp;
}
 
BigInt &operator^=(BigInt & a,const BigInt & b){
    BigInt Exponent, Base(a);
    Exponent = b;
    a = 1;
    while(!Null(Exponent)){
        if(Exponent[0] & 1)
            a *= Base;
        Base *= Base;
        divide_by_2(Exponent);
    }
    return a;
}
BigInt operator^(BigInt & a,BigInt & b){
    BigInt temp(a);
    temp ^= b;
    return temp;
}
 
void divide_by_2(BigInt & a){
    int add = 0;
    for (int i = a.digits.size() - 1; i >= 0;i--){
        int digit = (a.digits[i] >> 1) + add;
        add = ((a.digits[i] & 1) * 5);
        a.digits[i] = digit;
    }
    while(a.digits.size() > 1 && !a.digits.back())
        a.digits.pop_back();
}
 
BigInt sqrt(BigInt & a){
    BigInt left(1), right(a), v(1), mid, prod;
    divide_by_2(right);
    while(left <= right){
        mid += left;
        mid += right;
        divide_by_2(mid);
        prod = (mid * mid);
        if(prod <= a){
            v = mid;
            ++mid;
            left = mid;
        }
        else{
            --mid;
            right = mid;
        }
        mid = BigInt();
    }
    return v;
}
 
BigInt NthCatalan(int n){
    BigInt a(1),b;
    for (int i = 2; i <= n;i++)
        a *= i;
    b = a;
    for (int i = n + 1; i <= 2 * n;i++)
        b *= i;
    a *= a;
    a *= (n + 1);
    b /= a;
    return b;
}
 
BigInt NthFibonacci(int n){
    BigInt a(1), b(1), c;
    if(!n)
        return c;
    n--;
    while(n--){
        c = a + b;
        b = a;
        a = c;
    }
    return b;
}
 
BigInt Factorial(int n){
    BigInt f(1);
    for (int i = 2; i <= n;i++)
        f *= i;
    return f;
}
 
istream &operator>>(istream &in,BigInt&a){
    string s;
    in >> s;
    int n = s.size();
    for (int i = n - 1; i >= 0;i--){
        if(!isdigit(s[i]))
            throw("INVALID NUMBER");
        a.digits[n - i - 1] = s[i];
    }
    return in;
}
 
ostream &operator<<(ostream &out,const BigInt &a){
    for (int i = a.digits.size() - 1; i >= 0;i--)
        cout << (short)a.digits[i];
    return cout;
}

/*	------------- CAUTION ------------

-> BigInt must be related with string all time.
-> BigInt number is stored in reverse order in templ. CAREFUL!!!
-> num[x] gives the xth digit from right to left, 0-based index.

-> input:
BigInt x;
string s; cin >> s; // NOT -> cin >> x;
x = s; x += s; x *= s; x /= s; ........

-> declar.
BigInt x; BigInt x(343499449ull); BigInt x("9483493944");BigInt x = "343535";
-> oper.
BigInt x("3434"), y("3444"), z; z  = x + y; ........

*/


int main(void){
	stop_sync;
	untie_ios;
	#ifndef ONLINE_JUDGE
		//freopen("generator.txt", "r", stdin);
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		freopen("error.txt", "w", stderr);
	#endif
	
	int t(1), tcase(0);
	//cin >> t; 
	while(++tcase, t--){
		//cout << "--------Case #" << tcase << ": --------\n";
		BigInt num("0"); 
		for(int i = 0; i < 100; ++i){
			BigInt xi;
			string s;
			cin >> s;
			xi = s;
			num += xi;
		}
		// cout << num << ln;
		for(int i = length(num) - 1; i >= 0 && i >= length(num) - 10; --i) cout << num[i];
	}
	return 0;
}


/*
some familiar issues & sugg.:
!----> [RE-READ THE CODE!]
!----> [invariants to array?]
!----> [what about freq of elem/chars?]
!----> [kinda back-tracking?]
!----> [use clear() at last if resize() used!]
!----> [look at global variables and their values]
!----> [llabs() for long long int type]
!----> [look at input size and time limit]
!----> [No sync with puts fn]
!----> [prefix vs suffix]
!----> [binary search? -> ubd, lbd]
!----> [array contains duplicate values!]
!----> [(a/b+1)*b vs uceil(a,b)*b]
!----> [unq_v for vec only]
!----> [bitmask vs unsigned; (1ull << i) -> pow2]
!----> [use gcd(), NOT __gcd() for ai < 0]
!----> [rec. lambda: function<ret.type(param types,..)>fn_name = ....lambda fn && always dyn arr(vec, ..]

*/
