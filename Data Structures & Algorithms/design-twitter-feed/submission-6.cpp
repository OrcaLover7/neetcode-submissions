class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> follow_map;
    int time = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
        if((int)tweets[userId].size() > 10) tweets[userId].erase(tweets[userId].begin());
    }
    
    vector<int> getNewsFeed(int userId) {
        using container = tuple<int, int, const vector<pair<int, int>>*, int>;
        priority_queue<container> max_heap;

        //seeding
        if(tweets[userId].size()) max_heap.emplace(tweets[userId].back().first, tweets[userId].back().second, &tweets[userId], (int)tweets[userId].size() - 1);

        for(auto folo : follow_map[userId]){
            auto it = tweets.find(folo);
            if(it == tweets.end()) continue;

            auto& arr = it->second;

            if(arr.size()) max_heap.emplace(arr.back().first, arr.back().second, &arr, (int)arr.size() - 1);
        }

        //actual computation of ans
        vector<int> ans;

        while(!max_heap.empty() and ans.size() < 10){
            auto [t, id, vec_ptr, idx] = max_heap.top();
            max_heap.pop();

            ans.push_back(id);

            if(idx > 0){
                int n_t = (*vec_ptr)[idx-1].first;
                int n_id = (*vec_ptr)[idx-1].second;
                max_heap.emplace(n_t, n_id, vec_ptr, idx-1);
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) follow_map[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto it = follow_map.find(followerId);
        if(it != follow_map.end()){
            auto& st = it->second;
            st.erase(followeeId);
        }
    }
};
