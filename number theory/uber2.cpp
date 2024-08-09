#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(int t, vector<vector<int>> testcases) {
    vector<vector<int>> ans;
    
    for (int i = 0; i < t; i++) {
        vector<int> temp = testcases[i];
        sort(temp.begin(), temp.end());
        bool found = false;

        do {
            int uDelta = temp[0];  
            int uSpeed = temp[1];  
            int uAlpha = temp[2];  
            int uBeta = temp[3];   
                int time = (uAlpha - uDelta) / 2;
                int distance = (uAlpha + uDelta) / 2;
                if (time > 0&& abs(distance) > time && distance/time == uSpeed &&
                    distance * time == uBeta) {
                    ans.push_back({distance, time});
                    found = true;
                    break;
                }
        } while (next_permutation(temp.begin(), temp.end()));

        if (!found) {
            ans.push_back({-1, -1});
        }
    }
    return ans;
}


int main() {
    int t = 1;
    vector<vector<int>> testcases = {{3, 4, 8, 12}};
    vector<vector<int>> result = solution(t, testcases);

    for (auto &res : result) {
        for (auto &val : res) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

