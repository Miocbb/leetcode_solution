#ifndef _LEETCODE_INCLUDE_LIST_H_
#define _LEETCODE_INCLUDE_LIST_H_

#include <iostream>
#include <memory>

struct ListNode {
    int val;
    std::shared_ptr<ListNode> next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode() : val(0), next(nullptr) {}
    ListNode(const ListNode &node) : val(node.val), next(node.next) {}
};

class LinkList {
  private:
    std::shared_ptr<ListNode> head_;
    std::shared_ptr<ListNode> tail_;

  public:
    LinkList() : head_{nullptr}, tail_{nullptr} {}
    LinkList(ListNode &node)
    {
        auto new_node = std::make_shared<ListNode>(node);
        head_ = new_node;
        auto p = head_;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        tail_ = p;
    }

    // append node at the end.
    void append(const ListNode &node)
    {
        auto new_node = std::make_shared<ListNode>(node);
        if (head_ == nullptr) {
            head_ = tail_ = new_node;
        } else {
            tail_->next = new_node;
            tail_ = new_node;
            while (tail_->next != nullptr)
            {
                tail_ = tail_->next;
            }
        }
    }

    // insert under index i;
    void insert(size_t i, const ListNode &node)
    {
        auto new_node = std::make_shared<ListNode>(node);
        auto t = new_node;
        // insert before head_
        if (i <= 0) {
            while (t->next != nullptr)
            {
                t = t->next;
            }
            t->next = head_;
            head_ = new_node;
        } else {
            size_t count = 0;
            auto p = head_;
            while (count != i && p->next != nullptr)
            {
                p = p->next;
                count++;
            }
            auto head__of_rest = p->next;
            p->next = new_node;
            while (p->next != nullptr) {
                p = p->next;
            }
            p->next = head__of_rest;
        }

    }

    // get head_ node.
    ListNode * head() {return head_.get();}

    void show()
    {
        std::shared_ptr<ListNode> p = head_;
        while (p != nullptr)
        {
            std::cout << p->val << " -> ";
            p = p->next;
        }
        std::cout << "null\n";
    }
};

#endif // _LEETCODE_INCLUDE_LIST_H_
