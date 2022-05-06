class RecentCounter {
    queue<int> que;
public:
    RecentCounter() {

    }
    
    int ping(int t) {
        while (!que.empty()) {
            auto top = que.front();
            if (t-top > 3000) {
                que.pop();
            } else {
                break;
            }
        }
        que.push(t);
        return que.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */