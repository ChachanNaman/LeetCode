https://leetcode.com/problems/max-consecutive-ones-iii/description/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right =0, maxlen = 0, len = 0;
        int zeroes = 0;
        while(right < n){
            if(nums[right] == 0) {
                zeroes++;
            }
            if(zeroes > k){
                if(nums[left] == 0 ){
                    zeroes--;
                }
                left++; //move left until or unless 
            }
            if(zeroes <= k){
                len = right-left+1;
                maxlen = max(maxlen, len);
            }
            right++; //move right untill or unless
        }
        return maxlen;
    }
};