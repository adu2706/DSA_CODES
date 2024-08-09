#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

unordered_map<int, vector<vector<int>>> threeSumMap(vector<int>& nums) {
    unordered_map<int, vector<vector<int>>> sumMap;
    int n = nums.size();
    
    if (n < 3) return sumMap;
    
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n - 2; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicate values
        
        int left = i + 1;
        int right = n - 1;
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            
            sumMap[sum].push_back({nums[i], nums[left], nums[right]});
            
            if (sum == 0) {
                while (left < right && nums[left] == nums[left + 1]) left++; // Skip duplicates
                while (left < right && nums[right] == nums[right - 1]) right--; // Skip duplicates
                
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    return sumMap;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]]++;
    }

    map<int, int> twosum;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            twosum[arr[i] + arr[j]]++;
        }
    }

    unordered_map<int, vector<vector<int>>> threesum = threeSumMap(arr);

    int ans = 0;

    for (auto v : mp) {
        if (v.second >= 3) {
            int sum = v.first * 3;
            if (threesum.count(sum)) {
                ans += (v.second * (v.second - 1) * (v.second - 2)) / 6;
            }
        }
    }

    for (auto v : mp) {
        if (v.second >= 2) {
            int sum = v.first * 2;
            if (twosum.count(sum)) {
                ans += (v.second * (v.second - 1)) / 2 * (twosum[sum] - 1) / 2;
            }
        }
    }

    cout << ans/2 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
