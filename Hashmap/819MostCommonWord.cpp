//819. Most Common Word
//https://leetcode.com/problems/most-common-word/?envType=problem-list-v2&envId=hash-table

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> mm;
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        // we are converting words banned string into an set to check in O(1)
        // time , better approach than simply using vector string
        string word = "";
        int maxfreq = 0;
        string maxans = "";
        for (int i = 0; i < paragraph.size(); i++) {
            char ch = paragraph[i];
            if (isalpha(ch)) {
                word += tolower(ch); // converting to normal lowercase
                                     // word
            } else if (word != "") {
                if (bannedSet.find(word) == bannedSet.end()) {
                    // first find word is there or not in
                    // bannedset[bannedSet.find(word)] bannedSet.end()->means
                    // not found
                    mm[word]++; // increase count of that word
                }
                if (mm[word] > maxfreq) { // will compare int part of map
                    maxfreq = mm[word];
                    maxans = word;
                }
                word = ""; // reset word for next word use in paragraph
            }
        }

        // This line is outside the loop, and runs after all characters have
        // been processed.
        // At this point, if word still contains characters (like "ball"), we
        // manually check and process it.
        if (word != "") {
            if (bannedSet.find(word) == bannedSet.end()) {
                mm[word]++;
                if (mm[word] > maxfreq) {
                    maxfreq = mm[word];
                    maxans = word;
                }
            }
        }

        return maxans;
    }
};