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

    int event_dist, usage, dist;
    string event, trash;
    while(1) {
        int leaks = 0, last_dist = 0;
        double ans = 0, temp = 0;
        cin >> trash >> trash >> trash >> usage;
        if(usage == 0) break;
        while(1) {
            cin >> event_dist >> event;
            dist = event_dist-last_dist;
            temp += (leaks*dist)+(usage*(dist/100.0));
            ans = max(ans, temp);
            last_dist = event_dist;
            if(event == "Fuel") cin >> trash >> usage;
            else if(event == "Goal") break;
            else if(event == "Leak") ++leaks;
            else if(event == "Mechanic") leaks = 0;
            else if(event == "Gas") {
                cin >> trash;
                temp = 0;
            }
        }
        cout << fixed << setprecision(3) << ans << NEWL;
    }

    // int usage, event_dist;
    // string trash, event;
    // while(1) {
    //     vector<pair<int, pair<string, int>>> vec;
    //     cin >> trash >> trash >> trash >> usage;
    //     if(!usage) break;
    //     vec.pb({0, {"Fuel", usage}});
    //     while(1) {
    //         cin >> event_dist >> event;
    //         if(event == "Fuel") {
    //             cin >> trash >> usage;
    //             vec.pb({event_dist, {event, usage}});
    //         }
    //         else if(event == "Goal") {
    //             vec.pb({event_dist, {event, 0}});
    //             break;
    //         }
    //     }
    // }
    //
    // int event_dist, usage, dist;
    // string event, trash;
    // while(1) {
    //     int leaks = 0, last_dist = 0;
    //     double ans = 0, temp = 0;
    //     cin >> trash >> trash >> trash >> usage;
    //     if(usage == 0) break;
    //     while(1) {
    //         cin >> event_dist >> event;
    //         dist = event_dist-last_dist;
    //         temp += (leaks*dist)+(usage*(dist/100.0));
    //         ans = max(ans, temp);
    //         last_dist = event_dist;
    //         if(event == "Fuel") cin >> trash >> usage;
    //         else if(event == "Goal") break;
    //         else if(event == "Leak") ++leaks;
    //         else if(event == "Mechanic") leaks = 0;
    //         else if(event == "Gas") {
    //             cin >> trash;
    //             temp = 0;
    //         }
    //     }
    //     cout << fixed << setprecision(3) << ans << NEWL;
    // }
    //
    // 
    // bitset<100000> bs, fails, works;
    // bs.reset(), fails.reset(), works.reset();
    // int left = 0, right = 100000-1;
    // while(left <= right) {
    //     int mid = (left+right)/2;
    //     
    //     if((mid == 0 || fails[mid-1]) && works[mid]) break;
    //     else if(works[mid]) right = mid-1;
    //     else left = mid+1;
    // }

    return 0;
}
