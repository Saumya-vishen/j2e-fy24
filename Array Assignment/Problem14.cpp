#include <iostream>
#include <vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxCount = 0;
    int currentCount = 0;

    for (int num : nums) {
        if (num == 1) {
            currentCount++;
            maxCount = max(maxCount, currentCount);
        } else {
            currentCount = 0;
        }
    }

    return maxCount;
}

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    int maxConsecutiveOnes = findMaxConsecutiveOnes(nums);

    cout << "Maximum Consecutive Ones: " << maxConsecutiveOnes << endl;

    return 0;
}