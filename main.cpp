#include "headers/main.h"
#include "headers/hash.h"

using namespace hash;

int main(int argc, char **argv) {

    Hash obj;
    Timer timer;
    string in;

    cout << "VU Blockchain " << version << endl;

    cout << "------Choose an option------" << endl;
    cout << "1 - HASH A FILE (CMD arg)" << endl;
    cout << "2 - HASH A CUSTOM STRING (Console input)" << endl;
    int choice;
    cin >> choice;

    while (cin.fail() || (choice != 1 && choice != 2)) {
        cout << "Wrong input! Enter your choice:" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> choice;
    }

    std::ifstream file(argv[1]);

    if(choice == 1){
        if (argc < 2) {
            cout << "ERROR! No valid input file were found." << endl;
            return 0;
        }
        else if(file.is_open() && file.good()) {
            std::string stringFromFile((std::istreambuf_iterator<char>(file)),(std::istreambuf_iterator<char>()));
            obj.getInput(stringFromFile);
            cout << "HASHED FILE OUTPUT: " << endl;
            timer.startClock();
            cout << obj.hashThis();
            timer.endClock("File hashing process");
        }
    }
    else if(choice == 2){
        cout << "Please enter a string value to hash: " << endl;
        cin >> in;
        obj.getInput(in);
        cout << "HASHED STRING OUTPUT: " << endl;
        timer.startClock();
        cout << obj.hashThis();
        timer.endClock("Custom string hashing process");
    }

    return 0;
}
