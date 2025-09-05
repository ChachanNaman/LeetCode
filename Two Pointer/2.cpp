
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int>mpp;
        int left =0 , right = 0, maxlen = 0, len = 0;

        while(right < n){
            char ch = s[right]; //get the char at right index
            //then mpp[ch] means get the index of that char in map stored
            if(mpp.find(ch) != mpp.end()){//means already there in map then check
            //In map if elemenit does not exist, it returns mpp.end()
            //if exist then doesnt return mpp.end()
                if(mpp[ch] >= left){//if index of already existing char greater then current left then shift left next to it
                    left = mpp[ch]+1;
                }
            }
            len = right - left + 1; //upadte the length
            maxlen = max(maxlen , len);
            mpp[ch] = right; //update the right to new index if repeated
            right++;
        }
        return maxlen;
    }
};