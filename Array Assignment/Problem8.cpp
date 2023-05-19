#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
        return {};
    }

    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    vector<vector<int>> mergedIntervals;
    mergedIntervals.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] <= mergedIntervals.back()[1]) {
            mergedIntervals.back()[1] = max(mergedIntervals.back()[1], intervals[i][1]);
        } else {
            mergedIntervals.push_back(intervals[i]);
        }
    }

    return mergedIntervals;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> merged = mergeIntervals(intervals);

    cout << "Merged Intervals:" << endl;
    for (const auto& interval : merged) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}