#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) {
            return head;
        }

        ListNode* prev = nullptr;

        while(true) {
            ListNode* tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
            if(head==nullptr) {
                head = prev;
                break;
            }
        }

//        while(head!=nullptr) {
//            cout << head->val << " ";
//            head = head->next;
//        }

        return head;
    }
};

int main() {
    Solution solution = Solution();
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    solution.reverseList(head);

    return 0;
}