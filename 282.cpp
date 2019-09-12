/*
 * 282. Expression Add Operators
 *
 * Given a string that contains only digits 0-9 and a target value, return all possibilities
 * to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.
 *
 * Example 1:
 * Input: num = "123", target = 6
 * Output: ["1+2+3", "1*2*3"] 
 */
 
 class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        string temp;
        int prev = 0;
        int idx = 0;
        long tt = (long) target;
        helper(num, tt, res, temp, 0, prev, idx);
        return res;
    }
    
    void helper(const string& num, long target, vector<string>& res, string& temp,
                long curVal, long prev, int idx) {
        if(idx == num.size() && curVal == target) {
            //cout<<curVal <<" "<<target<<endl;
            res.push_back(string(temp));
            return;
        }
        // Starting at index idx, get a new number and append it to temp.
        for(int l=1; idx+l<=num.size(); ++l) {
            string ts = num.substr(idx, l);
            if (!isValidNumber(ts)) continue;
            string ss;
            long t = stol(ts);
            if(temp.empty()) {
                helper(num, target, res, ts, t, t, idx+l);
            } else {
                // +
                ss = temp+"+"+ts;
                helper(num, target, res, ss, curVal+t, t, idx+l);
                // -
                ss = temp+"-"+ts;
                helper(num, target, res, ss, curVal-t, -t, idx+l);
                // *
                ss = temp+"*"+ts;
                helper(num, target, res, ss, curVal-prev+prev*t, prev*t, idx+l);
            }
        }
    }
    
    bool isValidNumber(string& s) {
        if(s.size()>1 && s[0]=='0')
            return false;
        return true;
    }
};
