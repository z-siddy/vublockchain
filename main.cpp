#include "headers/main.h"
#include "headers/hash.h"

using namespace hash;

int main() {

    string in;

    cout << "VU Blockchain " << version << endl;

    cout << "Please enter a string value to hash: " << endl;
    cin >> in;

    Hash obj = Hash(in);



    return 0;
}