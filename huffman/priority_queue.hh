#pragma once

#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <utility>
#include <vector>

#include "node.hh"

class PriorityQueue
{
public:
    explicit PriorityQueue() = default;

    size_t size() const;

    void push(std::unique_ptr<Node> node);

    std::unique_ptr<Node> pop();

private:
    std::vector<std::unique_ptr<Node>> m_heap;
};
