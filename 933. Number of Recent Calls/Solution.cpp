class RecentCounter {
public:
    queue<int> counter;
    RecentCounter() {
    }
    
    int ping(int t) {
        counter.push(t);
        constexpr int threshold = 3000;
        while(!counter.empty() && t - counter.front() > threshold){
            counter.pop();
        }
        return counter.size(); 
    }
};

auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
