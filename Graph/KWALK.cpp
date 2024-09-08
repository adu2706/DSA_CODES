
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> vis, dis;

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

bool check(int x, int y){
    if (x < 0 || x >= n || y < 0 || y >= n) {
        return false;
    }
    return true;
}

vector<pair<int,int>> neighbours(int x, int y) {
    vector<pair<int,int>> ans;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (check(nx, ny)) {
            ans.push_back({nx, ny});
        }
    }
    return ans;
}

void bfs(int x, int y) {
    vis.assign(n, vector<int>(n, 0));
    dis.assign(n, vector<int>(n, 1e9));

    queue<pair<int,int>> q;
    dis[x][y] = 0;
    q.push({x, y});

    while (!q.empty()) {
        auto v = q.front();
        q.pop();

        int i = v.first;
        int j = v.second;

        if (vis[i][j] == 1) {
            continue;
        } else {
            vis[i][j] = 1;
        }

        for (auto neigh : neighbours(i, j)) {
            if (dis[neigh.first][neigh.second] > dis[i][j] + 1) {
                dis[neigh.first][neigh.second] = dis[i][j] + 1;
                q.push(neigh);
            }
        }
    }
}


int KnightWalk(int N, int sx, int sy, int ex, int ey)
{   n = N;
	sx--;
    sy--;
    ex--;
    ey--;
    bfs(sx, sy);
    if (dis[ex][ey] == 1e9) {
        return -1;
    } else {
        return dis[ex][ey];
    }
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	cin >> test_case;

	while (test_case--)
	{
		int N, Sx, Sy, Fx, Fy;
		cin >> N >> Sx >> Sy >> Fx >> Fy;

		cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
	}
}
