https://leetcode.com/problems/minimum-size-subarray-sum/description/?envType=problem-list-v2&envId=sliding-window

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0 , minlen = INT_MAX , len = 0;
        int sum = 0;
        while(right < n){
            sum = sum + nums[right];
            while(sum >= target){
                //get the len of current left and right  
                len = right - left +1;
                minlen = min(minlen, len);

                //search if i can minise the size and sum would be still greater then target
                sum = sum - nums[left]; //if i can subtarct and its still greater then
                left++;
            }
            right++;
        }
        if(minlen != 0 && minlen != INT_MAX){
            return minlen;
        }
        else{
            return 0;
        }

    }
};