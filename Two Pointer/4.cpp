https://leetcode.com/problems/fruit-into-baskets/description/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        // //TC -> O(2N)
        // int k = 2;
        // int left = 0, right = 0, maxlen = 0, len = 0;
        // unordered_map<int, int> mpp; //will store the fruit type and its frequency
        // int n = fruits.size();
        // while(right<n){
        //     mpp[fruits[right]]++; //new addition to my map 
        //     //if map have more than 2 type of fruits, i have to make it possible first then check for maxlen 
        //     if(mpp.size() > k){
        //         while(mpp.size() >k ){
        //             mpp[fruits[left]]--; //reduce count of fruit from map of left curr index
        //             if(mpp[fruits[left]] == 0){ //if reduce karte karte 0 hogya then remove krdo usko hash map se to have 2 type of fruits only
        //                 mpp.erase(fruits[left]); 
        //             }
        //             left++; //increase left till map doesnt have only 2 fruits
        //         }
        //     }
        //     if(mpp.size() <= k){ //everything fine
        //         len = right-left+1;
        //         maxlen = max(maxlen, len);
        //     }
        //     right++;
        // }
        // return maxlen;

        //TC -> O(N)
        int k = 2;
        int left = 0, right = 0, maxlen = 0, len = 0;
        unordered_map<int, int> mpp; //will store the fruit type and its frequency
        int n = fruits.size();
        while(right<n){
            mpp[fruits[right]]++; //new addition to my map 
            //if map have more than 2 type of fruits, i have to make it possible first then check for maxlen 
            if(mpp.size() > k){
            //in this trimmed the inner while loop , coz moving left one by one 
            //not directly straight its causing problem
                    mpp[fruits[left]]--; //reduce count of fruit from map of left curr index
                    if(mpp[fruits[left]] == 0){ //if reduce karte karte 0 hogya then remove krdo usko hash map se to have 2 type of fruits only
                        mpp.erase(fruits[left]); 
                    }
                    left++; //increase left till map doesnt have only 2 fruits
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


/*
What is unordered_map<int,int>?
It’s a C++ STL container that stores key–value pairs.
First int → key (your fruit type).
Second int → value (frequency counter).
So when you write:
unordered_map<int,int> mpp;
you’re saying:
“I want a hash table where keys are integers, and each key maps to an integer value.”

How mpp[key] works -> 
When you do:
mpp[2]++;
Two cases:
If 2 is not yet in the map:
unordered_map inserts a new entry with default value 0.
Then it increments → 0 + 1 = 1.

If 2 already exists:
It just fetches the value and increments it.

*/