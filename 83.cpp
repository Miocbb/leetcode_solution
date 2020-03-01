#include <vector>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}

    void show()
    {
        auto p = this;
        while (p != nullptr) {
            std::cout << p->val << " -> ";
            p = p->next;
        }
        std::cout << "null\n";
    }
};

class Solution {
  public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr) {
            return head;
        }
        auto curr_node = head;
        while (curr_node->next != nullptr) {
            auto next_node = curr_node->next;
            if (curr_node->val == next_node->val) {
                curr_node->next = next_node->next;
            } else {
                curr_node = curr_node->next;
            }
        }
        return head;
    }
};

int main()
{
    std::vector<ListNode> l = {ListNode(1), ListNode(1), ListNode(2),
                               ListNode(3), ListNode(3)};
    for (size_t i = 0; i < l.size() - 1; ++i) {
        l[i].next = &l[i+1];
    }
    l[0].show();

    Solution solver;
    auto head_node = solver.deleteDuplicates(&l[0]);
    head_node->show();
}
