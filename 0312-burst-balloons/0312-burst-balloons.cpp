class Solution {
public:
    int dp[305][305];
    
    int f(int i, int j, vector<int>& nums){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MIN;
        for(int k = i; k <= j; k++){
            int x = nums[k]*nums[i-1]*nums[j+1] + f(i, k-1, nums) + f(k+1, j, nums);
            ans = max(ans, x);
        }
        return dp[i][j] = ans;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        memset(dp, 0, sizeof(dp));
        int ans = INT_MIN;
        for(int i = n; i >= 1; i--){
            for(int j = 1; j <= n; j++){
                if(i > j) continue;
                int ans = INT_MIN;
                for(int k = i; k <= j; k++){
                    int x = nums[k]*nums[i-1]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    ans = max(ans, x);
                }
                dp[i][j] = ans;
            }
        }
        
        return dp[1][n];
    }
};