#ifndef SHANONCE_H
#define SHANONCE_H
#include <iostream>
#include <sstream>

#include <string>

std::string sha256(const std::string& input)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input.c_str(), input.length());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }

    return ss.str();
}

std::string mineBlock(const std::string& data)
{
    std::string nonce = "0";
    std::string blockData = data + nonce;
    std::string hash = sha256(blockData);

    while (hash.substr(0, 4) != "0000")
    {
        nonce = std::to_string(std::stoi(nonce) + 1);
        blockData = data + nonce;
        hash = sha256(blockData);
    }

    return hash;
}

int main()
{
    std::string data = "Block data";
    std::string minedHash = mineBlock(data);

    std::cout << "Mined Hash: " << minedHash << std::endl;

    return 0;
}

#endif // SHANONCE_H
