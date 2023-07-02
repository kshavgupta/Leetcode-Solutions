class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        for(auto &it: tasks) m[it]++;
        priority_queue<int> pq;
        for(auto &it: m) pq.push(it.second);
        queue<pair<int, int>> q; //Task freq, time
        int time = 1;
        for(; ; time++){
            if(!q.empty() && q.front().second <= time){
                pq.push(q.front().first);
                q.pop();
            }
            if(!pq.empty()){
                int top = pq.top();
                pq.pop();
                --top;
                if(top > 0) q.push({top, time + n + 1});
            }
            if(q.empty() && pq.empty()) break;
        }
        return time;
    }
};