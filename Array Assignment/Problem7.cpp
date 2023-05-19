#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxSubarraySum(vector<int>& nums) {
    int maxSum = INT_MIN;
    int currentSum = 0;

    for (int num : nums) {
        currentSum = max(num, currentSum + num);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int maxSum = maxSubarraySum(nums);
    
    cout << "Maximum subarray sum: " << maxSum << endl;

    return 0;
}