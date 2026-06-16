class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;

    int time = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++time, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> max_heap;

        for(auto tweet : tweets[userId]) max_heap.push(tweet);

        for(int followee : following[userId]) for(auto tweet : tweets[followee]) max_heap.push(tweet);

        vector<int> ans;

        while(!max_heap.empty() and (int)ans.size() < 10){
            ans.push_back(max_heap.top().second);
            max_heap.pop();
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

            auto it1 = st.find(followeeId);

            if(it1 != st.end()) st.erase(followeeId);
        }
    }
};
