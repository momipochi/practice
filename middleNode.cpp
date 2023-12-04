
#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// https://leetcode.com/problems/middle-of-the-linked-list/description/
ListNode *middleNode(ListNode *head)
{
    if (head->next == nullptr)
    {
        return head;
    }
    ListNode *curr = head;
    unsigned int length = 0;
    while (curr != nullptr)
    {
        curr = curr->next;
        length++;
    }
    curr = head;
    for (size_t i = 0; i < (length / 2) + 1; i++)
    {
        curr = curr->next;
    }
    return curr;
}

int main()
{
    vector<int> nums = {-1, 1, 0, -3, 3};
    // const auto &res = middleNode(nums);
    // for (size_t i = 0; i < res.size(); i++)
    // {
    //     cout << res[i] << " ";
    // }
}
