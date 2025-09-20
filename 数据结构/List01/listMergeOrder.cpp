#include <iostream>
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

// 将两个链表合并并排序
ListNode* mergeAndSortLists(ListNode* l1, ListNode* l2) {
    vector<int> vals;

    while (l1) {
        vals.push_back(l1->val);
        l1 = l1->next;
    }
    while (l2) {
        vals.push_back(l2->val);
        l2 = l2->next;
    }

    sort(vals.begin(), vals.end());

    if (vals.empty()) return nullptr;

    ListNode* head = new ListNode(vals[0]);
    ListNode* cur = head;
    for (size_t i = 1; i < vals.size(); i++) {
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
    }

    return head;
}

int main() {
    vector<int> arr1 = {3,1,2};
    vector<int> arr2 = {4,3,1,2};

    ListNode* l1 = createList(arr1);
    ListNode* l2 = createList(arr2);

    cout << "LIST first : ";
    printList(l1);
    cout << "LIST second : ";
    printList(l2);

    ListNode* merged = mergeAndSortLists(l1, l2);

    cout << "merged & sorted : ";
    printList(merged);

    return 0;
}
