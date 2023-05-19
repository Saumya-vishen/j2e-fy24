#include <iostream>
#include <string>
using namespace std;

int minDataPackets(string binaryString) {
    int count = 1;  
    int n = binaryString.length();
    
    for (int i = 1; i < n; i++) {
        if (binaryString[i] == binaryString[i - 1]) {
            count++;  
        }
    }
    
    return count;
}

int main() {
    string binaryString;
    cout << "Enter the binary string: ";
    cin >> binaryString;

    int packets = minDataPackets(binaryString);
    cout << "The minimum number of data packets required: " << packets << endl;

    return 0;
}