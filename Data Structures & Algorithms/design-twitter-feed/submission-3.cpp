class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, unordered_map<int, vector<int>>> feeds;

    int time = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++time, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        using Entry = tuple<int, int, const vector<pair<int, int>>*, int>;
        priority_queue<Entry> max_heap;

        if(tweets[userId].size()) max_heap.emplace(tweets[userId].back().first, tweets[userId].back().second, &tweets[userId], tweets[userId].size()-1);

        // for(auto tweet : tweets[userId]) max_heap.push(tweet);

        // for(int followee : following[userId]) for(auto tweet : tweets[followee]) max_heap.push(tweet);

        for(int followee : following[userId]){
            auto it = tweets.find(followee);
            if(it == tweets.end()) continue;
            auto& arr = it->second;

            if(arr.size()) max_heap.emplace(arr.back().first, arr.back().second, &arr, arr.size()-1);
        }

        vector<int> ans;

        while(!max_heap.empty() and (int)ans.size() < 10){
            auto [t, id, vec_ptr, idx] = max_heap.top();
            max_heap.pop();
            ans.push_back(id);

            if(idx > 0) {
                int n_t = (*vec_ptr)[idx-1].first;
                int n_id = (*vec_ptr)[idx-1].second;
                max_heap.emplace(n_t, n_id, vec_ptr, idx-1);
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto it = following.find(followerId);

        if(it != following.end()){
            auto& st = it->second;
            st.erase(followeeId);
        }
    }
};
