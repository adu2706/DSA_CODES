#include <bits/stdc++.h>
using namespace std;

int countAnalogousArrays(vector<int> consecutiveDifference, int lowerBound, int upperBound) {
    int n = consecutiveDifference.size();
    int min_start = lowerBound, max_start = upperBound;

    int current_min = 0, current_max = 0;
    
    for(int i = 0; i < n; i++) {
        current_min += consecutiveDifference[i];
        current_max += consecutiveDifference[i];
        min_start = max(min_start, lowerBound - current_min);
        max_start = min(max_start, upperBound - current_max);
    }

    if (min_start > max_start) return 0;

    return max_start - min_start + 1;
}

int main() {
    vector<int> consecutiveDifference = {-1, -3, 2};
    int lowerBound = 2;
    int upperBound = 8;

    int result = countAnalogousArrays(consecutiveDifference, lowerBound, upperBound);
    cout << result << endl;

    return 0;
}
