#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

void solve() {
    int n;
    string s;
    cin >> s;
    n = s.length();
    map<string, int> ans;
    stack<int> st;
    int mult = 1;
    int i = n - 1;
    while (i >= 0) {
        string str;
        while (i >= 0 && s[i] >= '0' && s[i] <= '9') {
            str += s[i];
            i--;
        }
        if (i >= 0 && s[i] == ')') {
            if (str.length()!=0) {
                reverse(str.begin(), str.end());
                int num = stoll(str);
                st.push(num);
                mult *= num;
            }
            i--;
        } else if (i >= 0 && s[i] == '(') {
            if (!st.empty()) {
                mult /= st.top();
                st.pop();
            }
            i--;
        } else if (i > 0 && s[i] >= 'a' && s[i] <= 'z') {
            string temp = "";
            while(i>0 && s[i]>='a' && s[i]<='z'){
                temp+=s[i];
                i--;
            }
            temp+=s[i];
            i--;
            reverse(temp.begin(), temp.end());
            reverse(str.begin(), str.end());
            int num;
            if (str.length() > 0) {
                num = stoll(str);
            } else {
                num = 1;
            }
            if (ans.find(temp) != ans.end()) {
                ans[temp] += num * mult;
            } else {
                ans[temp] = num * mult;
            }
        } else if (i >= 0 && s[i] >= 'A' && s[i] <= 'Z') {
            string temp = "";
            temp += s[i];
            reverse(str.begin(), str.end());
            int num;
            if (str.length() > 0) {
                num = stoll(str);
            } else {
                num = 1;
            }
            if (ans.find(temp) != ans.end()) {
                ans[temp] += num * mult;
            } else {
                ans[temp] = num * mult;
            }
            i--;
        }
    }

    string out = "";
    for (auto v : ans) {
        if (v.second > 1) {
            out += v.first;
            out += to_string(v.second);
        } else {
            out += v.first;
        }
    }
    cout << out << endl;
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
