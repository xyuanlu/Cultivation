/*
* 846. Hand of Straights
* 
* Alice has a hand of cards, given as an array of integers.
* Now she wants to rearrange the cards into groups so that
* each group is size W, and consists of W consecutive cards.
*
* Return true if and only if she can.
*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        //if (hands.size() != W*W)
        //    return false;
        
        // count of each value
        map<int, int> m;
        for(int i:hand) {
            m[i]++;
        }
        int K=W;
        int found = 0;
        
        while(m.size()!=0) {
            int i=0;
            int start = m.begin()->first;
            m.begin()->second--;
            //cout<<start<<" "<<m.begin()->second<<endl;
            if (m.begin()->second==0)
                m.erase(start);
            found++;
            while(found!=K) {
                auto it = m.find(start+found);
                if (it == m.end()) {
                    //cout<<start<<endl;
                    return false;
                }
                //cout<<it->first<<" ";
                it->second--;
                if (it->second==0)
                    m.erase(it);
                found++;
            }
            found=0;
            W--;
            cout<<endl;
        }
        /*cout<<W<<" "<<m.size()<<endl;
        for(auto& it:m) {
            cout<<it.first<<" "<<it.second<<endl;
        }*/
        return m.size()==0;
    }
};
