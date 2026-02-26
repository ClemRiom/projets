#include "encode_decode.hh"

std::string huffmanEncode(const std::string& message,
                          std::unordered_map<char, std::string> table)
{
    auto encoded = std::string{};
    for (unsigned char c : message)
        encoded += table[c];

    return encoded;
}

std::string huffmanDecode(const std::string& compressed_message,
                          std::unordered_map<char, std::string> table)
{
    auto rev_table = std::unordered_map<std::string, char>{};
    for (auto i = table.begin(); i != table.end(); ++i)
        rev_table[i->second] = i->first;

    std::string message = "";
    std::string cur = "";
    for (const char c : compressed_message)
    {
        cur += c;
        if (rev_table.contains(cur))
        {
            message += rev_table.at(cur);
            cur = "";
        }
    }

    return message;
}
