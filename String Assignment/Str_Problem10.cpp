#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string getNextPermutation(string word) {
   
    int i = word.length() - 2;
    while (i >= 0 && word[i] >= word[i + 1]) {
        i--;
    }

    if (i < 0) {
        return "no answer";  
    }

    int j = word.length() - 1;
    while (j > i && word[j] <= word[i]) {
        j--;
    }

    
    swap(word[i], word[j]);

    reverse(word.begin() + i + 1, word.end());

    return word;
}

int main() {
    string word;
    cout << "Enter the word: ";
    cin >> word;

    string nextPermutation = getNextPermutation(word);
    cout << "Next lexicographically greater permutation: " << nextPermutation << endl;

    return 0;
}