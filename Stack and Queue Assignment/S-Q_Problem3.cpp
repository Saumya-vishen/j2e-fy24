#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> findMaximums(int arr[], int N, int K) {
    vector<int> result;
    deque<int> dq;

    for (int i = 0; i < K; i++) {
        
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }

       
        dq.push_back(i);
    }

    for (int i = K; i < N; i++) {
        result.push_back(arr[dq.front()]);

        while (!dq.empty() && dq.front() <= i - K) {
            dq.pop_front();
        }

        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    result.push_back(arr[dq.front()]);

    return result;
}

int main() {
    int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 3;

    vector<int> maximums = findMaximums(arr, N, K);

    cout << "Maximums of each contiguous subarray of size " << K << ":" << endl;
    for (int num : maximums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}