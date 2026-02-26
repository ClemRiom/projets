#include "priority_queue.hh"

namespace
{
    auto compare_nodes = [](const std::unique_ptr<Node>& a, const std::unique_ptr<Node>& b) {
        return a->weight > b->weight;
    };
}

size_t PriorityQueue::size() const
{
    return m_heap.size();
}

void PriorityQueue::push(std::unique_ptr<Node> node)
{
    m_heap.push_back(std::move(node));
    std::push_heap(m_heap.begin(), m_heap.end(), compare_nodes);
}

std::unique_ptr<Node> PriorityQueue::pop()
{
    if (m_heap.empty())
    {
        throw std::runtime_error("Cannot pop from an empty PriorityQueue");
    }

    std::pop_heap(m_heap.begin(), m_heap.end(), compare_nodes);
    auto node = std::move(m_heap.back());
    m_heap.pop_back();

    return node;
}
