class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, more;
        int eq = 0;
        for(auto num : nums) {
            if(num < pivot) {
                less.push_back(num);
            } else if(num > pivot) {
                more.push_back(num);
            } else {
                eq++;
            }
        }
        for(int i = 0; i < eq; i++) {
            less.push_back(pivot);
        }
        for(auto num : more) {
            less.push_back(num);
        }
        return less;
    }
};