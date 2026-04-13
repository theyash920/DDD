class Solution {
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int, int>> result;

        if (!head) return result;

        Node *first = head;
        Node *second = head;

        // Move second pointer to the last node
        while (second->next != NULL) {
            second = second->next;
        }

        // Two-pointer approach on doubly linked list
        while (first != second && second->next != first) {
            int sum = first->data + second->data;

            if (sum == target) {
                result.push_back({first->data, second->data});
                first = first->next;
                second = second->prev;
            } else if (sum < target) {
                first = first->next;   // Need larger sum
            } else {
                second = second->prev; // Need smaller sum
            }
        }

        return result;
    }
};