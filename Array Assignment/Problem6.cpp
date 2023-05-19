#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<vector<int>>& result, vector<int>& nums, int start) {
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }

    for (int i = start; i < nums.size(); ++i) {
        if (i > start && nums[i] == nums[start])
            continue;

        swap(nums[i], nums[start]);
        backtrack(result, nums, start + 1);
        swap(nums[i], nums[start]);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    backtrack(result, nums, 0);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations = permuteUnique(nums);

    cout << "Unique Permutations:" << endl;
    for (const auto& permutation : permutations) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}