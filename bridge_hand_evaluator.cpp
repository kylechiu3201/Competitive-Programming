#include <bits/stdc++.h>
#define clubs 0
#define diamonds 1
#define hearts 2
#define spades 3
#define ace 0
#define jack 1
#define queen 2
#define king 3

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string line;
    string num_to_letter = "CDHS";
    while(getline(cin, line)) {
        int faces[4][4] = {0};
        int suits[4] = {0};
        int score1 = 0, score2 = 0;
        bool stopped[4] = {0};
        int n = line.size();
        char card = '*', suit = '*';
        for(int i = 0; i <= n; ++i) {
            if(card == '*') {
                card = line[i];
                card = (card == 'A') ? 1 : (card == 'J') ? 11 : (card == 'Q') ? 12 : (card == 'K') ? 13 : (card == 'T') ? 10 : card-'0';
            }
            else if(suit == '*') {
                suit = line[i];
                suit = (suit == 'C') ? 0 : (suit == 'D') ? 1 : (suit == 'H') ? 2 : 3;
            }
            else {
                ++suits[suit];
                if(card == 1 || (card >= 11 && card <= 13)) ++faces[card == 1 ? 0 : card-10][suit];
                card = '*', suit = '*';
            }
        }
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 4; ++j) {
                bool sub = (i == king && faces[i][j] && suits[j]-1 == 0) || (i == queen && faces[i][j] && (suits[j]-1) <= 1) || (i == jack && faces[i][j] && (suits[j]-1) <= 2);
                score1 += ((i == 0) ? 4 : i)*faces[i][j]-sub;
                stopped[j] = faces[ace][j] || (faces[king][j] && (suits[j]-1)) || (faces[queen][j] && (suits[j]-1 >= 2));
            }
            score2 += (suits[i] == 2)+2*(suits[i] == 1)+2*(suits[i] == 0);
        }
        int total = score1+score2;
        if(total < 14) cout << "PASS";
        else if(score1 >= 16 && stopped[0] && stopped[1] && stopped[2] && stopped[3]) cout << "BID NO-TRUMP";
        else if(total >= 14) {
            int most = 0, chosen_suit = -1;
            for(int i = 0; i < 4; ++i) if(suits[i] >= most) most = suits[i], chosen_suit = i;
            cout << "BID " << num_to_letter[chosen_suit];
        }
        cout << '\n';
    }
}
