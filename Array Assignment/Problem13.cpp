#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height) {
    int maxWater = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left < right) {
        int currentWater = min(height[left], height[right]) * (right - left);
        maxWater = max(maxWater, currentWater);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxWater;
}

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int maxContainer = maxArea(height);

    cout << "Maximum Water: " << maxContainer << endl;

    return 0;
}