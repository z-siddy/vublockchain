//
// Created by zygsi on 9/13/2019.
//

#ifndef VUBLOCKCHAIN_HASH_H
#define VUBLOCKCHAIN_HASH_H

#include "main.h"

namespace hash {

    class Hash {
    private:
        string _hashedValue;
        string _inputValue;
        string _b1;
        string _b2;
        string _b3;
        string _b4;
        void divideToBlocks();
        void blockToInt();
        void blockToHex();
        string getHashedValue();
    public:
        explicit Hash(string input):_inputValue(std::move(input)) { };
        void getInput();
        void hashThis();
    };

}

#endif //VUBLOCKCHAIN_HASH_H
