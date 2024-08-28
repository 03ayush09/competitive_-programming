#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        string s;
        cin >> s;

        int h = 0;
        int v = 0;


        bool yes = false;
        for (int i = 1 ; i <= s.size(); i++) {
            char it = s[i - 1];
            if (it == 'R') h++;
            if (it == 'L') h--;
            if (it == 'U') v++;
            if (it == 'D') v--;
            int dis = abs(x - h) + abs(y - v);
            if (dis <= i && dis % 2 == i % 2) {
                yes = 1;
                break;
            }
        }

        if (yes) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

}