#include <bits/stdc++.h>
using namespace std;

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<pss> vpss;
typedef vector<vpss> vvpss;
typedef unordered_map<int, int> umii;
typedef map<int, int> mii;
typedef unordered_set<int> usi;
typedef set<int> si;

const double EPS = 1e-9;
const int INF = 1000000005;
const long long INFF = 1000000000000000005LL;
const double PI = 3.1415926535897932384626433832795;
const int MOD = 1000000007;
const char NEWL = '\n';

ll min(ll a, int b) { if(a < b) return a; return b; }
ll min(int a, ll b) { if(a < b) return a; return b; }
ll max(ll a, int b) { if(a > b) return a; return b; }
ll max(int a, ll b) { if(a > b) return a; return b; }
string to_upper(string a) { for(int i = 0; i < (int)a.size(); ++i) if(a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a'-'A'; return a; }
string to_lower(string a) { for(int i = 0; i < (int)a.size(); ++i) if(a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a'-'A'; return a; }
bool is_prime(int a) { if(a == 1) return 0; for(int i = 2; i <= round(sqrt(a)); ++i) if(a%i == 0) return 0; return 1; }
bool is_prime(ll a) { if(a == 1) return 0; for(int i = 2; i <= round(sqrt(a)); ++i) if(a%i == 0) return 0; return 1; }

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define in_range(i,a,b) ((i >= min(a, b)) && (i <= max(a, b)))
#define get_dirs(i,j) {{(i)-1, (j)}, {(i)+1, (j)}, {(i), (j)-1}, {(i), (j)+1}}
#define TESTS(x) int x; cin >> x; while(x--)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define FOR(i,n) for(int i = 0; i < n; ++i)
#define RFOR(i,n) for(int i = n-1; i >= 0; --i)
#define REP(i,j,n) for(int i = j; i < n; ++i)
#define RREP(i,n,j) for(int i = n-1; i >= j; --i)
#define FOREACH(a,b) for(auto& (a) : (b))
#define FORIT(a) for(auto it = a.begin(); it != a.end(); ++it)
#define MAX(a,b) a = max(a, b)
#define MIN(a,b) a = min(a, b)
#define SQR(a) ((ll)(a)*(a))
#define SIZE(a) (int)((a).size())
#define SORT(a) sort(ALL(a))
#define SORTR(a) sort(RALL(a))
#define REVERSE(a) reverse(ALL(a))
#define NEXT_PERM(a) next_permutation(ALL(a))

template <class T>
void print_vec(vector<T> &v) { cout << "{"; for(auto x : v) cout << x << ", "; cout << "\b\b}"; }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    // int l, r, s, b;
    // int s, b;
    // int left[100005], right[100005];
    // vi left(100005), right(100005);
    for(;;) {
        int s, b;
        // scanf("%d %d", &s, &b);
        cin >> s >> b;
        if(!s && !b) break;
        int left[100005], right[100005];
        for(int i = 1; i <= s; ++i) left[i] = i-1, right[i] = i+1;
        left[1] = 0, right[s] = 0;
        for(; b--;) {
            int l, r;
            cin >> l >> r;
            // scanf("%d %d", &l, &r);
            // if(right[r] != -1)
            left[right[r]] = left[l];
            // left[l] == 0 ? printf("*") : printf("%d", left[l]);
            left[l] == 0 ? cout << "*" : cout << left[l];
            // cout << (left[l] == -1 ? "*" : to_string(left[l]));
            // if(left[l] == -1) printf("*");
            // else printf("%d", left[l]);
            // if(left[l] != -1)
            right[left[l]] = right[r];
            // right[r] == 0 ? printf(" *\n") : printf(" %d\n", right[r]);
            right[r] == 0 ? cout << " *\n" : cout << " " << right[r] << NEWL;
            // cout << (right[r] == -1 ? " *\n" : " "+to_string(right[r])+NEWL);
            // if(right[r] == -1) printf(" *\n");
            // else printf(" %d\n", right[r]);
        }
        cout << "-\n";
        // printf("-\n");
    }

    return 0;
}
