#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N_MAX = 14;
int n;

vector<int> queen(N_MAX, -1);
int knights_queen[N_MAX][N_MAX];

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int check2(int row, int col) {
    for (int i = 0; i < 8; i++) {
        int nx = row + dx[i];
        int ny = col + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && knights_queen[nx][ny] == 1) {
            return 0;
        }
    }
    return 1;
}

bool check1(int row, int col) {
    for (int prow = 0; prow < row; prow++) {
        int pcol = queen[prow];
        if (pcol == col || abs(row - prow) == abs(col - pcol)) {
            return false;
        }
    }
    return true;
}

int rec(int level) {
    if (level == n) {
        return 1;
    }
    int ans = 0;
    for (int col = 0; col < n; col++) {
        if (check1(level, col) && check2(level, col)) {
            queen[level] = col;
            knights_queen[level][col] = 1;
            ans += rec(level + 1);
            knights_queen[level][col] = -1;
            queen[level] = -1;
        }
    }
    return ans;
}

void solve() {
    cin >> n;
    memset(knights_queen, -1, sizeof(knights_queen));
    cout << rec(0) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
