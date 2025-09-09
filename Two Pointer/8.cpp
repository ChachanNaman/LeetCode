https://leetcode.com/problems/binary-subarrays-with-sum/description/?envType=problem-list-v2&envId=sliding-window

class Solution {
public:
    int solve(vector<int>& nums, int goal){
        int left = 0, right =0, sum = 0, count = 0;
        int n = nums.size();
        while(right < n){
            if(goal < 0){
                return 0;
            }
            sum = sum + nums[right];
            while(sum > goal){ //shrinking
                sum = sum - nums[left];
                left++;
            }
            count = count + (right-left+1);
            right++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return ( solve(nums, goal) - solve(nums, goal-1));
    }
};