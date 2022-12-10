class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> pq;
        
        for(int i = 0; i < arr.size(); i++){
            pq.push({abs(arr[i] - x), arr[i]});
            if(pq.size() > k) pq.pop();
        }
        
        vector<int> ans;
        while(!pq.empty()){
            int f = pq.top().second;
            ans.push_back(f);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};