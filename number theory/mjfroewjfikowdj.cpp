int calculate_team_effort(const vector<vector<int>>& S, int mask) {
    int effort = 0;
    int n = S.size();
    for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
            for (int j = i + 1; j < n; ++j) {
                if (mask & (1 << j)) {
                    effort += S[i][j];
                }
            }
        }
    }
    return effort;
}

int max_effort_reduction(int N, const vector<vector<int>>& S) {
    int total_masks = 1 << N;
    vector<int> dp(total_masks, 0);

    for (int mask = 1; mask < total_masks; ++mask) {
        dp[mask] = calculate_team_effort(S, mask);
    }

    for (int mask = 1; mask < total_masks; ++mask) {
        for (int sub = mask; sub; sub = (sub - 1) & mask) {
            dp[mask] = max(dp[mask], dp[sub] + dp[mask ^ sub]);
        }
    }

    return dp[total_masks - 1];
}


