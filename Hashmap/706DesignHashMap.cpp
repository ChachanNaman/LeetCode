//706. Design HashMap
//https://leetcode.com/problems/design-hashmap/description/

#include <map>

class MyHashMap {
public:
 map<int , int >myHashMap;
    MyHashMap() {
       
    }
    
    void put(int key, int value) {
        // pair<int , int > p = make_pair(key,value);
        // myHashMap.insert(p);  //this approach will not update the value keep the value same 
        myHashMap[key] = value;  //will update the value if called key again with another value
    }
    
    int get(int key) {
        if(myHashMap.find(key) != myHashMap.end()){// means if key found , if its equal then key not found
            return myHashMap[key];
        }
        return -1;

    }
    void remove(int key) {
        myHashMap.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */