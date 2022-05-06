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
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<pss> vpss;
typedef vector<vpss> vvpss;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, vector<int>> umivi;
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
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define elif else if
#define GCD(a,b) __gcd(a,b)
#define LCM(a,b) (a*(b/gcd(a,b)))
#define IN_RANGE(i,a,b) ((i >= min(a, b)) && (i <= max(a, b)))
#define GET_DIRS(i,j) {{(i)-1, (j)}, {(i)+1, (j)}, {(i), (j)-1}, {(i), (j)+1}}
#define SWAP(a,b) a ^= b; b ^= a; a ^= b
#define NUM_DIG(n) (floor(log10(n))+1)
#define IS_POW_2(n) (n && (!(n&(n-1))))
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
#define SCI(a) scanf("%d", &(a))
#define SCII(a,b) scanf("%d %d", &(a), &(b))
#define SCIII(a,b,c) scanf("%d %d %d", &(a), &(b), &(c))
#define SCL(a) scanf("%lld", &(a))
#define SCC(a) scanf("%c", &(a))
#define SCS(a) scanf("%s", (a))
#define PNEWL printf("\n")
#define PF printf

template <class T>
void PVEC(vector<T> &v) { cout << "{"; for(auto x : v) cout << x << ", "; cout << "\b\b}"; }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    const pii EXIT = {INT_MAX, INT_MAX};
    int r, c, s;
    char temp;
    unordered_map<char, pii> m = {{'N', {-1, 0}}, {'S', {1, 0}}, {'E', {0, 1}}, {'W', {0, -1}}};
    while(1) {
        cin >> r >> c >> s;
        if(!r && !c && !s) break;
        --s;
        vvpii grid(r, vpii(c));
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                cin >> temp;
                pii cur = {i+m[temp].fi, j+m[temp].se};
                if(cur.fi < 0 || cur.fi >= r || cur.se < 0 || cur.se >= c) cur = {INT_MAX, INT_MAX};
                grid[i][j] = cur;
            }
        }
        pii slow = {0, s}, fast = {0, s};
        int count_exit = 0;
        while(fast != EXIT && grid[fast.fi][fast.se] != EXIT) {
            pii save = fast;
            slow = grid[slow.fi][slow.se];
            fast = grid[fast.fi][fast.se];
            fast = grid[fast.fi][fast.se];
            ++count_exit;
            if(fast == save) --count_exit;
            if(slow == fast) break;
        }
        bool loop = slow == fast && fast != EXIT && grid[0][s] != EXIT;
        int before = 0;
        if(loop) {
            slow = {0, s};
            while(slow != fast) {
                slow = grid[slow.fi][slow.se];
                fast = grid[fast.fi][fast.se];
                ++before;
            }
        }
        else {
            while(slow != EXIT) {
                slow = grid[slow.fi][slow.se];
                ++count_exit;
            }
        }
        if(loop) cout << before << " step(s) before a loop of " << count_exit << " step(s)" << '\n';
        else cout << count_exit << " step(s) to exit" << '\n';
    }

    return 0;
}