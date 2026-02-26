#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "node.hh"
#include "priority_queue.hh"

std::unique_ptr<Node> buildHuffmanTree(const std::string& message);

std::unordered_map<char, std::string>
buildCodeTable(const std::unique_ptr<Node>& node);
