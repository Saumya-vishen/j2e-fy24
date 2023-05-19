#include <iostream>
#include <vector>

using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int n = candies.size();
    int maxCandies = 0;

    for (int i = 0; i < n; i++) {
        maxCandies = max(maxCandies, candies[i]);
    }

    vector<bool> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = (candies[i] + extraCandies) >= maxCandies;
    }

    return result;
}

int main() {
    vector<int> candies = {4, 2, 1, 1, 2};
    int extraCandies = 1;

    vector<bool> result = kidsWithCandies(candies, extraCandies);
    for (bool value : result) {
        cout << boolalpha << value << " ";
    }
    cout << endl;

    return 0;
}