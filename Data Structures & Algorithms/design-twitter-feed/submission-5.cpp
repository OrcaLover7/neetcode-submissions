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
        priority_queue<pair<int, int>> max_heap;

        for(auto tweet : tweets[userId]) max_heap.push(tweet);

        for(auto fol : follow_map[userId]) for(auto tweet : tweets[fol]) max_heap.push(tweet);

        vector<int> ans;

        while(!max_heap.empty() and (int)ans.size() < 10){
            ans.push_back(max_heap.top().second);
            max_heap.pop();
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
