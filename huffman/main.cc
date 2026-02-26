#include <iostream>

#include "encode_decode.hh"
#include "huffman.hh"

int main()
{
    const std::string message = "Test message!";
    std::cout << "Original message: " << message << "\n";
    const auto root = buildHuffmanTree(message);
    const auto table = buildCodeTable(root);
    const std::string compressed = huffmanEncode(message, table);
    std::cout << "Compressed message: " << compressed << "\n";
    const std::string decompressed = huffmanDecode(compressed, table);
    std::cout << "Decompressed message: " << decompressed << "\n";
    return 0;
}
