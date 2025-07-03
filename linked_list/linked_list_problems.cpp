// ===== Leetcode 25: Reverse Nodes in k-Group =====
// https://leetcode.com/problems/reverse-nodes-in-k-group/
// Approach: Reverse k nodes at a time using head insertion

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class ReverseKGroup {
public:
    int sizef(ListNode* first) {
        int size = 0;
        while (first != NULL) {
            first = first->next;
            size++;
        }
        return size;
    }

    void insert_at_head(ListNode*& head, int d) {
        ListNode* temp = new ListNode(d);
        temp->next = head;
        head = temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = sizef(head);
        int groupCount = size / k;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevgroup = dummy;

        while (groupCount > 0) {
            ListNode* temp = NULL;
            for (int i = 0; i < k; i++) {
                insert_at_head(temp, head->val);
                head = head->next;
            }

            prevgroup->next = temp;
            while (prevgroup->next != NULL) {
                prevgroup = prevgroup->next;
            }
            prevgroup->next = head;

            groupCount--;
        }
        return dummy->next;
    }
};

// ===== Leetcode 23: Merge k Sorted Lists =====
// https://leetcode.com/problems/merge-k-sorted-lists/
// Approach: Flatten all nodes, sort, rebuild list

class MergeKLists {
public:
    void easy(ListNode*& head, int data) {
        ListNode* temp = new ListNode(data);
        if (!head) {
            head = temp;
            return;
        }
        ListNode* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> vals;
        for (auto node : lists) {
            while (node) {
                vals.push_back(node->val);
                node = node->next;
            }
        }

        sort(vals.begin(), vals.end());

        ListNode* head = NULL;
        for (int v : vals) {
            easy(head, v);
        }

        return head;
    }
};

// ===== Leetcode 61: Rotate List =====
// https://leetcode.com/problems/rotate-list/
// Approach: Find length, break at (n-k), connect tail to head

class RotateList {
public:
    int size(ListNode* head) {
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int n = size(head);
        k = k % n;
        if (k == 0) return head;

        ListNode* curr = head;
        for (int i = 0; i < n - k - 1; i++) {
            curr = curr->next;
        }

        ListNode* newHead = curr->next;
        curr->next = NULL;

        ListNode* tail = newHead;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = head;

        return newHead;
    }
};

// ===== Leetcode 143: Reorder List =====
// https://leetcode.com/problems/reorder-list/
// Approach: Split, reverse second half, and merge alternately

class ReorderList {
public:
    int size(ListNode* head) {
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        return count;
    }

    void reverse(ListNode*& head, int data) {
        ListNode* temp = new ListNode(data);
        temp->next = head;
        head = temp;
    }

    void reorderList(ListNode* head) {
        int n = size(head);
        if (n < 3) return;

        ListNode* current = head;
        for (int i = 1; i < n / 2; i++) {
            current = current->next;
        }

        ListNode* middle = nullptr;
        ListNode* secondHalf = nullptr;

        if (n % 2 == 0) {
            secondHalf = current->next;
            current->next = nullptr;
        } else {
            middle = current->next;
            secondHalf = middle->next;
            middle->next = nullptr;
            current->next = nullptr;
        }

        ListNode* reversed = nullptr;
        ListNode* temp = secondHalf;
        while (temp) {
            reverse(reversed, temp->val);
            temp = temp->next;
        }

        ListNode* first = head;
        ListNode* second = reversed;

        while (first && second) {
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;

            first->next = second;
            second->next = t1;

            first = t1;
            second = t2;
        }

        if (middle) {
            ListNode* tail = head;
            while (tail->next) {
                tail = tail->next;
            }
            tail->next = middle;
        }
    }
};
