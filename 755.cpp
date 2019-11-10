/*
* 755. Pour Water
*/

class Solution {
public:
    // Simulation
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        //vector<int> dx = {-1, 1};
        int found = K;
        while(V>0) {
            for(int d=-1; d<=1; d+=2) {
                 for(int l=K; l+d>=0 && l+d<heights.size(); l=l+d) {
                     if (heights[l+d]<heights[l]) {
                         found=l+d;
                         //cout<<found<<endl;
                     } else if (heights[l+d]>heights[l]) {
                         break;
                     }
                 }
                if (found!=K) {
                    heights[found]++;
                    break;
                }
            }
            --V;
            if (found==K) {
                heights[K]++;
            }
            found = K;
        }
        return heights;
    }
};
