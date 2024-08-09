#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,k;
vector<int> seats;
bool check(int minDist) {
    int count = 1;  
    int last_position = seats[0];
    
    for (int i = 1; i < n; i++) {
        if (seats[i] - last_position >= minDist) {
            count++;
            last_position = seats[i];
            if (count == k) {
                return true;
            }
        }
    }
    return false;
}

void solve() {
    cin >> n >> k;
    seats.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> seats[i];
    }
    
    sort(seats.begin(), seats.end());

    int low = 1; 
    int high = seats[n - 1] - seats[0]; 
    int result = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid)) {
            result = mid;  
            low = mid + 1;  
        } else {
            high = mid - 1; 
        }
    }
    
    cout << result << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
