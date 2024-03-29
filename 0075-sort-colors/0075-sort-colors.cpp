class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size()-1, mid = 0;
        while(mid <= j){
            if(nums[mid] == 0) swap(nums[mid++], nums[i++]);
            else if(nums[mid] == 1) mid++;
            else swap(nums[mid], nums[j--]);
        }
    }
};