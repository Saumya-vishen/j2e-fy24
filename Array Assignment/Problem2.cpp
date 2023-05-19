#include <vector>
#include <iostream>
using namespace std;

int maxArea(vector<int>& height) {
    int maxArea = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left < right) {
        int h = min(height[left], height[right]);
        int width = right - left;
        int area = h * width;
        maxArea = max(maxArea, area);

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return maxArea;
}

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = maxArea(height);
    cout << "Maximum amount of water that can be stored: " << result << endl;

    return 0;
}