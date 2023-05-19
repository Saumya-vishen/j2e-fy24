#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int closestSum = 0;
    int minDiff = INT_MAX;
    int n = nums.size();
    
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            int diff = abs(target - sum);
            
            if (diff < minDiff) {
                minDiff = diff;
                closestSum = sum;
            }
            
            if (sum < target)
                left++;
            else
                right--;
        }
    }
    
    return closestSum;
}

int main() {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int result = threeSumClosest(nums, target);
    cout << "Closest sum to target: " << result << endl;

    return 0;
}