class Solution {
    class LNode {
    public:
        LNode(int v, LNode* n = nullptr) : val(v), next(n) {}
        int val;
        LNode* next;
    };
public:
    int findTheWinner(int n, int k) {
        LNode* head = nullptr;
        auto pre = head;
        for (int i = 1; i <= n; ++i) {
            LNode* node = new LNode(i);
            if (head == nullptr) {
                head = node;
                pre = head;
            } else {
                pre->next = node;
                pre = node;
            }
        }
        pre->next = head;
        //auto cur = head;
        while (/*n > 1*/pre->next!=pre) {
            //n--;
            for (int i = 1; i < k; ++i) {
                //cur = cur->next;
                pre = pre->next;
            }
            auto del = pre->next;
            pre->next = pre->next->next;
            delete del;
        }
        int res = pre->val;
        delete pre;
        return res;
    }
};