//
// Created by zygsi on 9/13/2019.
//

#ifndef VUBLOCKCHAIN_HASH_H
#define VUBLOCKCHAIN_HASH_H

#include <chrono>
#include "main.h"
#include <vector>
#include <random>
#include <sstream>
#include <fstream>

namespace hash {

    class Timer {
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> time;
    public:
        Timer() : time {std::chrono::high_resolution_clock::now()} {}
        double timePassed() {
            return
                std::chrono::duration<double> (std::chrono::high_resolution_clock::now() - time).count();
        }
        void timerReset() {
            time = std::chrono::high_resolution_clock::now();
        }
    };

    class Hash {
    private:
        string _hashedValue;
        string _inputValue;
        std::vector<int> hashVec;
        void divideToBlocks() {
            for(auto i = _inputValue.begin(); i != _inputValue.end(); ++i) {
                hashVec.push_back((*i)^hashVec.size());
            }
        };
        void getHashedValue() {
            long long int seed = _inputValue.length() * _inputValue.length();
            std::mt19937 rand(seed);
            std::uniform_int_distribution<int> variant(0,2);
            std::uniform_int_distribution<int> number(48, 57);
            std::uniform_int_distribution<int> letter(97, 102);
            std::uniform_int_distribution<int> sletter(65, 70);
            std::stringstream hashStream;
            for (int i=0;i<64;i++){
                int var = variant(rand);
                if(var == 0)
                    hashStream << (char)number(rand);
                else if(var == 1)
                    hashStream << (char)letter(rand);
                else
                    hashStream << (char)sletter(rand);
            }
            _hashedValue = hashStream.str();
        };
    public:
        void getInput(string in) {
            _inputValue = in;
        };

        void readFile(std::ifstream *input) {
            if(*input){
                string fileInput ((std::istreambuf_iterator<char>(*input)), std::istreambuf_iterator<char>());
                _inputValue = fileInput;
            }
            else throw "Error while opening the input file.";
        };

        string hashThis() {
            divideToBlocks();
            getHashedValue();
            return _hashedValue;
        };
    };

}

#endif //VUBLOCKCHAIN_HASH_H
