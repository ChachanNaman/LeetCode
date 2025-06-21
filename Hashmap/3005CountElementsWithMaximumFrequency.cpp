//3005. Count Elements With Maximum Frequency
//https://leetcode.com/problems/count-elements-with-maximum-frequency/description/

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxfreq = 0;
        int maxans = 0;
        unordered_map <int, int> count;
        for(int i = 0; i< nums.size(); i++){
            count[nums[i]]++;
            maxfreq = max(maxfreq , count[nums[i]]);  //to count freq of each number in array and to store max in maxfreq
        }

        for(int i = 0 ; i<nums.size(); i++){
            if(maxfreq == count[nums[i]]){
                maxans++;

            }
        }
        return maxans;

    }
};