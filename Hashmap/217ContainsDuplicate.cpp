//217. Contains Duplicate
//https://leetcode.com/problems/contains-duplicate/description/?envType=problem-list-v2&envId=hash-table

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // stack<int> s;

        // for (int i = 0; i < nums.size(); i++) {
        //     s.push(nums[i]);
        // }

        // int n = s.size();
        // vector<int> arr(n);

        // for (int i = 0; i < n; i++) {
        //     //s.pop() is a void thing doesnt return any value , islie s.top
        //     arr[i] = s.top();
        //     s.pop();
        // }

        // for (int i = 0; i < n; ++i) {
        //     for (int j = i + 1; j < n; ++j) {
        //         if (arr[i] == arr[j])
        //             return true;
        //     }
        // }
        // return false;

        unordered_map<int , int > m;
        for(int i : nums){
            if(m[i]>=1){
                return true;
            }
            m[i]++;  //mapping is happening here -> 4 comes then check count ->0 then make a count++ <4,1> then 2 comes check count ->0 then make a count++ <2,1> ->>>>> <value , count>
        }
        return false;
    }
};

