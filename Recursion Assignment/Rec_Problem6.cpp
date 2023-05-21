#include <iostream>
#include <vector>

using namespace std;

void printSubsetSums(vector<int>& nums, int index, int sum, vector<int>& subsetSums) {
    int n = nums.size();

    if (index == n) {
        subsetSums.push_back(sum);
        cout << sum << " ";
        return;
    }

    printSubsetSums(nums, index + 1, sum + nums[index], subsetSums);

    printSubsetSums(nums, index + 1, sum, subsetSums);
}

int main() {
    int n;
    cout << "Enter the size of the set: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> subsetSums;

    cout << "Sums of all subsets: ";
    printSubsetSums(nums, 0, 0, subsetSums);

    return 0;
}