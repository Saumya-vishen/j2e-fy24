#include <iostream>

using namespace std;

void moveDisk(int disk, char source, char destination) {
    cout << "Move disk " << disk << " from tower " << source << " to tower " << destination << endl;
}

void solveTowersOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        moveDisk(n, source, destination);
        return;
    }

    solveTowersOfHanoi(n - 1, source, destination, auxiliary);
    moveDisk(n, source, destination);
    solveTowersOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    char source = 'A';
    char auxiliary = 'B';
    char destination = 'C';

    cout << "Moves to solve the Towers of Hanoi problem:" << endl;
    solveTowersOfHanoi(n, source, auxiliary, destination);

    return 0;
}