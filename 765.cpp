/*
 * 765. Couples Holding Hands
 */
 
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        /* 
         * Find the first misplaced couple, fix it.
         * For a couple AB, since this is the first mismatched
         * couple, the A' should be somewhere later then AB
         */
        
        // couple's id and their idxs
        unordered_map<int, vector<int>> m;
        for(int i=0; i<row.size(); ++i) {
            m[row[i]/2].push_back(i);
        }
        
        int res = 0;
        
        for(int i=0; i<row.size()/2; ++i) {
            // matched couple
            if(row[i*2]/2 == row[i*2+1]/2) {
                continue;
            } else { // misplaced AB
                // idx of A
                int idx = row[i*2]/2;
                int b1 = m[idx][0];
                int b2 = m[idx][1];
                int targetIdx;
                if (b1 == i*2) {
                    targetIdx = b2;
                } else {
                    targetIdx = b1;
                }
                // wsap B and row[targetIdx];
                int temp = row[i*2+1];
                row[i*2+1] = row[targetIdx];
                row[targetIdx] = temp;
                
                //cout<<idx<<" "<<targetIdx<<" "<<b1<<" "<<b2<<endl;
                // update the new idx of B
                if(m[temp/2][0] == i*2+1) {
                    m[temp/2] = vector<int>{targetIdx, m[temp/2][1]};
                } else {
                     m[temp/2] = vector<int>{targetIdx, m[temp/2][0]};
                }
                res++;
            }
            
        }
        return res;
    }
};
