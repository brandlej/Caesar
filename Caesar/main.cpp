#include <iostream>
#include <string>

namespace constants {
    constexpr int asciiLowerbound { 97 };
    constexpr int alphabetLength { 26 };
}

std::string encrypt(std::string word, int shift) {
    // init std::string var with a c-style string literal
    // this might get default initialized anwyays though
    std::string encrypted { "" };
    
    for(int i{ 0 }; i < word.length(); ++i) {
        const char currentChar = word[i];
        // map currentChar to 0-25 by subtracting 97
        // add shift
        // (above value) % 26 to get remainder
        // add back 97 to get ASCII value
        const char newChar = ((currentChar - constants::asciiLowerbound) + shift) % constants::alphabetLength;
        encrypted += (newChar + constants::asciiLowerbound);
    }

    return encrypted;
}

std::string decrypt(std::string encryptedWord, int shift) {
    std::string decryptedWord { "" };
    for(int i{ 0 }; i < encryptedWord.length(); ++i) {
        // map currentChar to 0-25 by subtracting 97
        // subtract shift
        // (above value) % 26 to get remainder
        // if negative, add 26 (e.g. -1 + 26 is 'z')
        // add back 97 to get ASCII value
        const char currentChar = encryptedWord[i];
        char newChar = ((currentChar - constants::asciiLowerbound) - shift) % constants::alphabetLength;
        if(newChar < 0) newChar += constants::alphabetLength;
        decryptedWord += (newChar + constants::asciiLowerbound);
    }

    return decryptedWord;
}

std::string promptUserInput() {
    std::string input {};
    std::cout << "Enter a word: ";
    std::cin >> input;
    
    return input;
}

int main() {
    // currently assumes lowercase letters between a and z inclusive
    std::string word { promptUserInput() };
    constexpr int shift = 3;
    std::string encryptedWord {encrypt(word, shift) };
    
    std::cout << "Encrypted -> " << encryptedWord << "\n";
    std::cout << "Decrypted -> " << decrypt(encryptedWord, shift) << "\n";
    
    return 0;
}
