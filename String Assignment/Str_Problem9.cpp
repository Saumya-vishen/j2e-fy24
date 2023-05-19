#include <iostream>
#include <string>
using namespace std;

string compressString(string message) {
    string compressed;

    int count = 1;
    for (int i = 1; i <= message.length(); i++) {
        if (i < message.length() && message[i] == message[i - 1]) {
            count++;
        } else {
            compressed += message[i - 1] + to_string(count);
            count = 1;
        }
    }

    return compressed;
}

int main() {
    string message;
    cout << "Enter the message: ";
    cin >> message;

    string compressedMessage = compressString(message);
    cout << "Compressed message: " << compressedMessage << endl;

    return 0;
}