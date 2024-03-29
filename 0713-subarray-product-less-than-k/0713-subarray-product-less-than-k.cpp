class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, j = 0, product = 1, ans = 0;
        while(j < n){
            product *= nums[j];
            while(i <= j && product >= k){
                product /= nums[i++];
            }
            j++;
            ans += (j-i);
        }
        return ans;
    }
};