class Solution {
public:
    
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        for(int j = 2; j <= m; j+=2){
            if(p[j-1] == '*'){
                dp[0][j-1] = 1;
                dp[0][j] = 1;
            }
            else break;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                
                    if(s[i-1] == p[j-1] || p[j-1] == '.') dp[i][j] = dp[i-1][j-1];
                    else if(p[j-1] == '*'){
                        if(p[j-2] == s[i-1] || p[j-2] == '.'){
                            dp[i][j] = dp[i][j-2] || dp[i-1][j];
                        }  
                        else dp[i][j] = dp[i][j-2];
                    } 
                
            }
        }
        return dp[n][m];
    }
};