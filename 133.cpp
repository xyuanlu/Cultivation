/*
 * 133. Clone Graph
 * 
 * Given a reference of a node in a connected undirected graph, return a deep copy (clone) of the graph.
 * Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.
 */
 
 /*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        vector<Node*> visited(101, nullptr);
        
        return helper(node, visited);
    }
    
    Node* helper(Node *node, vector<Node*>& visited) {
        //cout<<node->val<<endl;
        if(visited[node->val] != nullptr)
            return visited[node->val];
        Node *cur = new Node();
        cur->val = node->val;
        visited[node->val] = cur;
        for(Node *n : node->neighbors) {
            cur->neighbors.push_back(helper(n, visited));
        }
        return cur;
    }
};
