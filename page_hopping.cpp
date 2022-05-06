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

int main() {
    int a, b, t = 1, n = 105;
    while(1) {
        cin >> a >> b;
        if(a == 0 && b == 0) break;
        vvi graph(n, vi(n, INT_MAX));
        while(1) {
            graph[a][b] = 1;
            cin >> a >> b;
            if(a == 0 && b == 0) break;
        }
        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(graph[i][k] == INT_MAX || graph[k][j] == INT_MAX) continue;
                    graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
                }
            }
        }
        double total_weight = 0, total_nodes = 0;
        for(int i = 0; i < n; ++i) {
            bool flag = false;
            for(int j = 0; j < n; ++j) if(i != j && graph[i][j] != INT_MAX) total_weight += graph[i][j], flag = true;
            if(flag) ++total_nodes;
        }
        total_nodes *= (total_nodes-1);
        double ans = total_weight/total_nodes;
        cout << "Case " << t++ << ": average length between pages = " << fixed << setprecision(3) << ans << " clicks" << endl;
    }

    return 0;
}



