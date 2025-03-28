// 1710. Maximum Units on a Truck
// https://leetcode.com/problems/maximum-units-on-a-truck/

class Solution {
public:
    static bool compare(vector<int>& a1, vector<int>& a2) {
        return a1[1] > a2[1]; 
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int units =0 ;
        int i =0;

        sort(boxTypes.begin(), boxTypes.end(), compare);

        while(truckSize>0 && i<boxTypes.size()){
            if(boxTypes[i][0]<=truckSize){
            units += boxTypes[i][0]* boxTypes[i][1];
            truckSize -= boxTypes[i][0];}
            else{
                int fraction = truckSize;
                truckSize = 0;
                units += fraction* boxTypes[i][1];
            }
            i++;
        }
        return units;
    }
};