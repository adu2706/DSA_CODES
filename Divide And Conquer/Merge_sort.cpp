#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int inversion_count = 0;

vector<int> merge_sort(vector<int> &A, vector<int> &B) {
    vector<int> C(A.size() + B.size());
    int i = 0, j = 0, k = 0;
    while (i < A.size() && j < B.size()) {
        if (A[i] <= B[j]) {
            C[k++] = A[i++];
        } else {
            inversion_count += A.size()-i;
            C[k++] = B[j++];
        }
    }
    while (i < A.size()) {
        C[k++] = A[i++];
    }
    while (j < B.size()) {
        C[k++] = B[j++];
    }
    return C;
}

vector<int> Msort(vector<int> &A) {
    if (A.size() <= 1) return A;

    int mid = A.size() / 2;
    vector<int> left(A.begin(), A.begin() + mid);
    vector<int> right(A.begin() + mid, A.end());

    left = Msort(left);
    right = Msort(right);

    return merge_sort(left, right);
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    inversion_count = 0;
    vector<int> sorted_A = Msort(A);
    cout<<"Inversion Count :"<<inversion_count<<endl;
    for (int i = 0; i < n; i++) {
        cout << sorted_A[i] << " ";
    }
    cout <<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
