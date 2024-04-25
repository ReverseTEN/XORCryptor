#include <iostream>
#include <fstream>
#include <vector>

void encryptBinary(const std::string& inputFile, const std::string& outputFile, const std::string& key) {
    std::ifstream input(inputFile, std::ios::binary);
    std::ofstream output(outputFile, std::ios::binary);

    char byte;
    size_t keyIndex = 0;
    while (input.get(byte)) {
        byte ^= key[keyIndex++ % key.size()]; // XOR encryption with key
        output.put(byte);
    }

    input.close();
    output.close();
}

int main() {
    std::string inputFile = "payload.bin";
    std::string outputFile = "encrypted.bin";
    std::string key = "key123456"; //

    encryptBinary(inputFile, outputFile, key);

    std::cout << "Encryption complete." << std::endl;
    return 0;
}
