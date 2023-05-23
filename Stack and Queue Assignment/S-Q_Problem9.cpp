#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class StockSpanner {
private:
    stack<pair<int, int>> st; 

public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;

        while (!st.empty() && price >= st.top().first) {
            span += st.top().second;
            st.pop();
        }

        st.push(make_pair(price, span));

        return span;
    }
};

int main() {
    StockSpanner stock;

    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    cout << "Stock Spans: ";
    for (int price : prices) {
        cout << stock.next(price) << " ";
    }
    cout << endl;

    return 0;
}