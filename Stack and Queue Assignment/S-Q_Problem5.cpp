#include <iostream>
#include <vector>

using namespace std;

vector<int> arrangeDeck(int N) {
    vector<int> deck(N);

    for (int i = 0; i < N; i++) {
        deck[i] = i + 1;
    }

    vector<int> arrangement(N);
    int idx = 0;

    for (int i = 0; i < N; i++) {
        arrangement[idx] = deck[i];
        idx = (idx + 1) % N;
        deck.push_back(deck[i]);
    }

    for (int i = 1; i < N; i++) {
        if (arrangement[i] <= arrangement[i - 1]) {
            return {-1}; 
        }
    }

    return arrangement;
}

int main() {
    int N = 5;

    vector<int> result = arrangeDeck(N);

    if (result[0] == -1) {
        cout << "Arrangement is not possible for N = " << N << endl;
    } else {
        cout << "Arrangement for N = " << N << ":" << endl;
        for (int card : result) {
            cout << card << " ";
        }
        cout << endl;
    }

    return 0;
}