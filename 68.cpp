/*
 * 68. Text Justification
 * 
 * Given an array of words and a width maxWidth, format the text such that each line has exactly 
 * maxWidth characters and is fully (left and right) justified.
 * You should pack your words in a greedy approach; that is, pack as many words as you can in each
 * line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
 *
 * Extra spaces between words should be distributed as evenly as possible. If the number of spaces
 * on a line do not divide evenly between words, the empty slots on the left will be assigned more
 * spaces than the slots on the right.
 *
 * For the last line of text, it should be left justified and no extra space is inserted between words.
 */
 
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int K) {
        /*
         * Associate a space with te word after it and initial count to -1;
        */
        int count =-1;  // The length including one space the word follows it: abc_bcd_def
        int w = 0;          // word cound in a line , it has w-1 slots
        int gap = 0;    // extra space between word.  (K-count)/(w-1)
        int r = 0;      // r for remainer. first r slots will have one extra space apart from 1+gap.
        int prev=-1;     // previous end idx, should not be included in the current line.
        vector<string> res;
        for(int i=0; i<words.size(); ++i) {
            if (count + words[i].size()+1 == K) {
                //cout<<"1:"<<i<<" "<<count<<endl;
                string temp = words[prev+1];
                for(int h=prev+2; h<=i; ++h) {
                    temp += " "+words[h];
                }
                res.push_back(temp);
                prev = i;
                count = -1;
                w = 0;
                continue;
            } else if (count + words[i].size()+1 > K) {
                cout<<i<<" "<<count<<endl;
                if(w==1) {
                    gap = K-count;
                    r=0;
                } else {
                    gap = (K-count)/(w-1);
                    r = (K-count)%(w-1);
                }
                //cout<<"gaps "<<gap<<"r "<<r<<endl;
                string gaps;
                while (gap>0) {
                    gaps+=" ";
                    gap--;
                }
                string temp = words[prev+1];
                for(int h=prev+2; h<i; ++h) {
                    if(h-(prev+1) <= r) {
                        temp+=" ";
                    }
                    
                    temp += gaps+ " "+words[h];
                }
                count = -1;
                prev = i-1;
                gap = 0;
                w = 0;
                r=0;
                while(temp.size()<K) {
                    temp += " ";
                }
                res.push_back(temp);
                i--;
            } else {
                count += 1+words[i].size();
                w++;
            }
        }
            
        // last part
        //cout<<"last: "<<prev<<" "<<words.size()-1<<endl;
        if (prev < (int)words.size()-1) {
            string temp = words[prev+1];
            for(int h=prev+2; h<words.size(); ++h) {                
                temp += " "+words[h];
             //cout<<temp<<"*"<<endl;
            }
            while(temp.size()<K) {
                temp += " ";
            }
            res.push_back(temp);
        }
        
        return res; 
    }
};
