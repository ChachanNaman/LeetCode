/*
Same like 4.cpp fruit into basket

Longest Substring With At Most K Distinct Characters

Given a string s and an integer k.Find the length of the longest substring with at most k distinct characters.

Examples:
Input : s = "aababbcaacc" , k = 2
Output : 6
Explanation : The longest substring with at most two distinct characters is "aababb".
The length of the string 6.

Input : s = "abcddefg" , k = 3
Output : 4
Explanation : The longest substring with at most three distinct characters is "bcdd".
The length of the string 4.
*/

https://takeuforward.org/plus/dsa/problems/longest-substring-with-at-most-k-distinct-characters

class Solution {
public:
    int kDistinctChar(string& s, int k) {
        //your code goes here
        int n = s.size();
        unordered_map<char, int>mpp;
        int left =0 , right = 0, maxlen = 0, len = 0;

        while(right < n){
            char ch = s[right];
            mpp[ch]++;
            if(mpp.size()>k){
                mpp[s[left]]--; //reduce the freq
                if(mpp[s[left]] == 0){
                    mpp.erase(s[left]);//remove the type //erasing the key soo s[left]
                }
                left++;
            }
            if(mpp.size() <= k){ //everything fine
                len = right-left+1;
                maxlen = max(maxlen, len);
            }
            right++;
        }
        return maxlen;
    }
};