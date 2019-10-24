#include "headers/main.h"
#include "headers/hash.h"


using namespace hash;

std::string random_string()
{
    std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

    std::mt19937 generator(time(0)*rand());

    std::shuffle(str.begin(), str.end(), generator);

    return str.substr(0, 5);    // assumes 32 < number of characters in str
}
int main(int argc, char **argv) {

    Hash obj;
    Timer timer;
    string in;

    cout << "VU Blockchain " << version << endl;

    cout << "------Choose an option------" << endl;
    cout << "1 - HASH A FILE (CMD arg)" << endl;
    cout << "2 - HASH A CUSTOM STRING (Console input)" << endl;
    cout << "3 - COLLISION TEST WITH 1 000 000 STRING-O-PAIRS" << endl;
    int choice;
    cin >> choice;

    while (cin.fail() || (choice != 1 && choice != 2 && choice != 3)) {
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
        else {
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
    else if(choice == 3) {
        int collisions = 0;
        timer.startClock();
        for(int i=1;i<1000000;i++){
            string a = random_string();
            string b = random_string();
            while(a == b)
                b = random_string();
            Hash h1,h2;
            h1.getInput(a);
            h2.getInput(b);
            if(h1.hashThis() == h2.hashThis())
                collisions++;
        }
        timer.endClock("Generation and hashing process");
        cout << endl << "Number of collisions: " << collisions;
    }

    return 0;
}
