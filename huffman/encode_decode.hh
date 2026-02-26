#pragma once

#include <string>
#include <unordered_map>

std::string huffmanEncode(const std::string& message,
                          std::unordered_map<char, std::string> table);

std::string huffmanDecode(const std::string& compressed_message,
                          std::unordered_map<char, std::string> table);
