#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

ListNode* createList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;
    for (size_t i = 1; i < arr.size(); i++) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

ListNode* unionUnorderedLists(ListNode* l1, ListNode* l2) {
    unordered_set<int> seen;
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (l1) {
        if (seen.insert(l1->val).second) { 
            tail->next = new ListNode(l1->val);
            tail = tail->next;
        }
        l1 = l1->next;
    }

    while (l2) {
        if (seen.insert(l2->val).second) {
            tail->next = new ListNode(l2->val);
            tail = tail->next;
        }
        l2 = l2->next;
    }

    return dummy.next;
}

int main() {
    vector<int> arr1 = {3,4,5};
    vector<int> arr2 = {2,3};

    ListNode* l1 = createList(arr1);
    ListNode* l2 = createList(arr2);

    cout << "first  : ";
    printList(l1);

    cout << "second : ";
    printList(l2);

    ListNode* merged = unionUnorderedLists(l1, l2);

    cout << "merged  : ";
    printList(merged);

    return 0;
}
