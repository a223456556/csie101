#include <iostream>
#include <string>

using namespace std;

string runLengthEncoding(string str) {
    int n = str.length();


    string encodedString = "";
    for (int i = 0; i < n; i++) {
     
        int count = 1;
        while (i < n - 1 && str[i] == str[i+1]) {
            count++;
            i++;
        }
     
        encodedString += str[i] + to_string(count);
    }
    return encodedString;
}

int main() {
    string str = "AABBBCCCCddd";
    cout << "Input string: " << str << endl;
    string encodedStr = runLengthEncoding(str);
    cout << "Encoded string: " << encodedStr << endl;
    return 0;
}
