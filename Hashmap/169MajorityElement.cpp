//169. Majority Element
//https://leetcode.com/problems/majority-element/description/?envType=problem-list-v2&envId=hash-table

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxfreq=0;
        int maxans=0;
        unordered_map<int , int > count;
        for (int i = 0 ; i < nums.size(); i++){
            count[nums[i]]++;
            maxfreq = max(maxfreq , count[nums[i]]);
        }

        for(int i = 0 ; i < nums.size(); i++){
            if(count[nums[i]]==maxfreq){//if my count of element equal to maxfreq then its the majority element soo return maxans
                maxans = nums[i];
                break;
            }
        }
        return maxans;
    }
};