//242. Valid Anagram
//https://leetcode.com/problems/valid-anagram/description/?envType=problem-list-v2&envId=hash-table

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char , int > strings;
        unordered_map<char ,int> stringt;

        if(s.length() != t.length()){
            return false;  //base case
        }

        for( char ch : s){
            strings[ch]++;  //will map all character in map with count
            //ex : a -> <a,1> , b-> <b,1>, a-> <a,2>
        }
        for(char ch : t){
            stringt[ch]++;
        }
        return strings == stringt;  //true if all char are in both and eequal in cout
    }   
};