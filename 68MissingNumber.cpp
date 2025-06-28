//68. Missing Number
//https://leetcode.com/problems/missing-number/description/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n+1 , -1);//initialse all with -1
        for(int i = 0 ; i <n;i++){
            v[nums[i]] = nums[i];  //place nums int value in vector array at nums int values->index
        }
        for(int i = 0 ; i < v.size(); i++){
            if(v[i]==-1){
                return i;
            }
        }
           return 0;
    }
};