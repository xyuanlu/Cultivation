/*
 * 973. K Closest Points to Origin
 */
 
class Solution {
public:
    class Node{
    public:
        int x;
        int y;
        float dis;
        Node(int xx, int yy, float d) : x(xx), y(yy), dis(d) {};
    };
    struct NodeCompareGreater{
        bool operator()(const Node& n1, const Node& n2){
            return n1.dis > n2.dis;
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        priority_queue<Node, vector<Node>, NodeCompareGreater> memo;
        for (int i=0; i<points.size(); ++i) {
            float dis = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            memo.push(Node(points[i][0], points[i][1], dis));
        }
        
        for(int i=0; i<K; ++i) {
            res.push_back(vector<int>{memo.top().x,memo.top().y});
            memo.pop();
        }
        return res;
    }
};
