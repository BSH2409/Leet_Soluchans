class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int> n(nums.begin(),nums.end());
        for(int i=1;i<k;i++)
            n.pop();
        return n.top();
    }
};