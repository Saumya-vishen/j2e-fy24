#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int i = left - 1;

    for (int j = left; j < right; ++j) {
        if (nums[j] <= pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }

    swap(nums[i + 1], nums[right]);
    return i + 1;
}

int quickSelect(vector<int>& nums, int left, int right, int k) {
    if (left == right) {
        return nums[left];
    }

    int pivotIndex = partition(nums, left, right);

    if (k == pivotIndex) {
        return nums[k];
    } else if (k < pivotIndex) {
        return quickSelect(nums, left, pivotIndex - 1, k);
    } else {
        return quickSelect(nums, pivotIndex + 1, right, k);
    }
}

int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    int targetIndex = n - k;  

    return quickSelect(nums, 0, n - 1, targetIndex);
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};  
    int k = 2; 

    int kthLargest = findKthLargest(nums, k);
    cout << "The kth largest element is: " << kthLargest << endl;

    return 0;
}