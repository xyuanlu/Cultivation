/*
 * 355. Design Twitter
 * Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:
 *
 * postTweet(userId, tweetId): Compose a new tweet.
 * getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each 
 *     item in the news feed must be posted by users who the user followed or by the user herself.
 *     Tweets must be ordered from most recent to least recent.
 * follow(followerId, followeeId): Follower follows a followee.
 * unfollow(followerId, followeeId): Follower unfollows a followee.
 */
 
 class Twitter {
public:
    class T{
    public:
        int id;
        int t;
    };
    
    class P{
    public:
        int userId;
        int idx;   // idx in tweet queue
    };
    
    /** Initialize your data structure here. */
    Twitter() {
        _t = 0;
        K = 10;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(m[userId].size() == K) {
            m[userId].pop_front();
        }
        m[userId].push_back({tweetId, _t++});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        auto compare = [this](const P& p1, const P& p2){
            return m[p1.userId][p1.idx].t < m[p2.userId][p2.idx].t;      
        };
        priority_queue<P, vector<P>, decltype(compare)> pq(compare);
        vector<int> res;
        if (m[userId].size()!=0)
            pq.push({userId, m[userId].size()-1});
        for(auto id:f[userId]) {
            //cout<<m[id].size()-1<<endl;
            if(m[id].size()!=0)
                pq.push({id, m[id].size()-1});
        }
        while(res.size()!=K && !pq.empty()) {
            res.push_back(m[pq.top().userId][pq.top().idx].id);
            if (pq.top().idx!=0)
                pq.push({pq.top().userId, pq.top().idx-1});
            pq.pop();
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followeeId == followerId)
            return;
        f[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        f[followerId].erase(followeeId);
    }
    
private:
    int _t;
    int K;
    /*
     * Deque: 
     * Random access - constant O(1)
     * Insertion or removal of elements at the end or beginning - constant O(1)
     * Insertion or removal of elements - linear O(n)
     */
    unordered_map<int, deque<T>> m;
    // user key follows a set of users
    unordered_map<int, unordered_set<int>> f;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
