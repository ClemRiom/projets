#include "huffman.hh"

std::unique_ptr<Node> buildHuffmanTree(const std::string& message)
{
    if (message.empty())
    {
        return nullptr;
    }

    std::unordered_map<char, float> frequencies;
    for (const char c : message)
    {
        frequencies[c] += 1.0f;
    }

    PriorityQueue pq;
    for (const auto& [character, freq] : frequencies)
    {
        pq.push(std::make_unique<Node>(freq, character));
    }

    while (pq.size() > 1)
    {
        auto left_child = pq.pop();
        auto right_child = pq.pop();

        float combined_weight = left_child->weight + right_child->weight;

        auto parent = std::make_unique<Node>(combined_weight,
                                             std::move(left_child),
                                             std::move(right_child));
        pq.push(std::move(parent));
    }

    return pq.pop();
}

namespace
{
    void traverse_tree(const std::unique_ptr<Node>& node,
                       const std::string& current_prefix,
                       std::unordered_map<char, std::string>& table)
    {
        if (!node)
        {
            return;
        }

        if (node->symbol.has_value())
        {
            table[node->symbol.value()] = current_prefix;
            return;
        }

        traverse_tree(node->left, current_prefix + "0", table);
        traverse_tree(node->right, current_prefix + "1", table);
    }
}

std::unordered_map<char, std::string> buildCodeTable(const std::unique_ptr<Node>& node)
{
    std::unordered_map<char, std::string> table;

    if (!node)
    {
        return table;
    }

    if (node->symbol.has_value() && !node->left && !node->right)
    {
        table[node->symbol.value()] = "0";
        return table;
    }

    traverse_tree(node, "", table);

    return table;
}
