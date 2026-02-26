#pragma once

#include <memory>
#include <optional>

struct Node
{
    Node() = default;
    Node(float weight_, std::optional<char> symbol_);
    Node(float weight_, std::unique_ptr<Node> left_,
         std::unique_ptr<Node> right_);
    float weight;
    std::optional<char> symbol;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
};
