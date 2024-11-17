class RecentCounter {
private:
    std::queue<int> requests;

public:
    RecentCounter() {
        // The queue is initially empty
    }
    
    int ping(int t) {
        // Add the new request timestamp
        requests.push(t);

        // Remove timestamps that are outside the range [t - 3000, t]
        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop();
        }

        // The size of the queue represents the number of requests in the range
        return requests.size();
    }
};
