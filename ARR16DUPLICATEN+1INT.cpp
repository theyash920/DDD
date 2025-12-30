//why do while loop 
//This ensures the loop runs at least once, allowing the Floyd's Cycle Detection algorithm to work correctly.
//Why it matters: This is Floyd's Tortoise and Hare algorithm. 
// The first phase needs to move both pointers before checking if they meet. Without the do-while, the algorithm fails immediately!
// The do-while is essential because we start both pointers at the same position (index 0), so they would meet immediately without moving if we used a regular while loop.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Floyd's Cycle Detection Algorithm (Tortoise and Hare)
        
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Find intersection point in the cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        // Phase 2: Find the entrance to the cycle (duplicate number)
        fast = nums[0];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};