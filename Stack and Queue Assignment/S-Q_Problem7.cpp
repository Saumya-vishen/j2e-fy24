#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1); 
    stack<int> st; 

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[i] > nums[st.top()]) {
            result[st.top()] = nums[i]; 
            st.pop();
        }
        st.push(i); 
    }

    return result;
}

int main() {
    vector<int> nums = {4, 6, 3, 2, 8, 1, 9};

    vector<int> result = nextGreaterElement(nums);

    cout << "Next Greater Elements:" << endl;
    for (int num : nums) {
        cout << num << ": " << result[num] << endl;
    }

    return 0;
}