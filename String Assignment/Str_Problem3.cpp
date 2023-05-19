#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int minMoves(string word) {
    unordered_map<char, int> leftCount, rightCount;
    int n = word.length();

    
    for (int i = 0; i < n; i++) {
        rightCount[word[i]]++;
    }

    int minMoves = n;  
    
    for (int i = 0; i < n; i++) {
        char c = word[i];
        leftCount[c]++;
        rightCount[c]--;
        minMoves = min(minMoves, leftCount[c] + rightCount[c]);
    }

    return minMoves;
}

int main() {
    string word;
    cout << "Enter the word: ";
    cin >> word;

    int moves = minMoves(word);
    cout << "The minimum number of moves required: " << moves << endl;

    return 0;
}