class Solution {
public:
    
    int maxHeight(vector<vector<int>>& cub) {
        int n = cub.size();
        for(auto &x: cub) sort(x.begin(), x.end());
        sort(cub.begin(), cub.end());
        vector<int> dp(n);
        int mx = INT_MIN;
        for(int i = 0; i < n; i++){
            dp[i] = cub[i][2];
            for(int j = 0; j < i; j++){
                if(cub[j][0] <= cub[i][0] && cub[j][1] <= cub[i][1] && cub[j][2] <= cub[i][2]){
                    if(dp[j]+cub[i][2] > dp[i]) dp[i] = dp[j] + cub[i][2];
                }
            }
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};