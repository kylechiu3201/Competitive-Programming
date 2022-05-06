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

int get_parent(vi& parent, int node) {
    if(parent[node] == -1) return node;
    return get_parent(parent, parent[node]);
}

void join(vi& parent, int par_u, int v) {
    int next = parent[v];
    parent[v] = par_u;
    if(next != -1) join(parent, par_u, next);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    typedef pair<double, pii> pdpii;
    int t, n, r, x, y, cse = 1;
    cin >> t;
    while(t--) {
        cin >> n >> r;
        vpii points(n);
        for(int i = 0; i < n; ++i) {
            cin >> x >> y;
            points[i] = {x, y};
        }
        priority_queue<pdpii, vector<pdpii>, greater<pdpii>> pq;
        vi visited(n, 0);
        pq.push({0, {0, 0}});
        int count = 0;
        int states = 0;
        double roads = 0, rails = 0;
        vi parent(n, -1);
        while(!pq.empty()) {
            auto front = pq.top(); pq.pop();
            double dist = front.fi;
            int source = front.se.fi, dest = front.se.se;
            if(visited[dest]) continue;
            visited[dest] = true;
            if(dist > r) rails += dist;
            else {
                roads += dist;
                int par_s = get_parent(parent, source), par_d = get_parent(parent, dest);
                if(par_s != par_d) join(parent, par_s, dest);
            }
            if(++count == n) break;
            for(int k = 0; k < n; ++k) {
                if(visited[k]) continue;
                int x_diff = points[k].fi-points[dest].fi, y_diff = points[k].se-points[dest].se;
                double dist = sqrt((x_diff*x_diff)+(y_diff*y_diff));
                pq.push({dist, {dest, k}});
            }
        }
        for(auto node : parent) if(node == -1) ++states;
        cout << "Case #" << cse++ << ": " << states << " " << round(roads) << " " << round(rails) << NEWL;
    }

    return 0;
}
