// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, B, H, W, price, beds;
    while(scanf("%d %d %d %d", &N, &B, &H, &W) == 4) {
    // while(cin >> N >> B >> H >> W) {
        int ans = B+1;
        for(int i = 0; i < H; ++i) {
            // cin >> price;
            scanf("%d", &price);
            price *= N;
            for(int j = 0; j < W; ++j) {
                // cin >> beds;
                scanf("%d", &beds);
                if(beds >= N)
                    ans = min(ans, price);
            }
        }
        if(ans > B)
            // cout << "stay home";
            printf("stay home\n");
        else
            printf("%d\n", ans);
            // cout << ans;
        // cout << '\n';
    }
    return 0;
}
