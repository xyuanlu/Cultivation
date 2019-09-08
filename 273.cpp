class Solution {
public:
    vector<pair<int, string>>
            ks{{1000000000, "Billion"}, {1000000, "Million"},
                                      {1000, "Thousand"}, {1, ""}};
    unordered_map<int, string> 
            digits{{0,""}, {1,"One"}, {2,"Two"}, {3,"Three"}, {4,"Four"},
                   {5, "Five"}, {6,"Six"}, {7, "Seven"}, {8, "Eight"}, 
                   {9,"Nine"}, {10, "Ten"}, 
                   {11,"Eleven"}, {12,"Twelve"}, {13,"Thirteen"}, {14,"Fourteen"},
                   {15,"Fifteen"}, {16, "Sixteen"}, {17,"Seventeen"},
                   {18, "Eighteen"}, {19,"Nineteen"}};
    unordered_map<int, string> 
            tens{ {20, "Twenty"}, {30, "Thirty"},
                 {40,"Forty"}, {50,"Fifty"}, {60,"Sixty"}, {70, "Seventy"},
                 {80, "Eighty"}, {90,"Ninety"}};
    
    
    string numberToWords(int num) {
        if(num==0)
            return "Zero";
        string res;
        auto it=ks.begin();
        while(num>=0 && it!=ks.end()) {
            int n = num/(it->first);
            //cout<<num<<" "<<it->first<<" "<<n<<endl;
            if(n==0) {
                ++it;
                continue;
            }
            helper(n, res);
            if(it->first >1)
                res = res + it->second + " ";
            //cout<<res<<endl;
            num=num%it->first;
            ++it;
        }
        res.pop_back();
        return res;
    }
    
    //num<1000
    void helper(int num, string& res) {
        int n = num/100;
        if(n>0) {
            res = res + digits[n] + " Hundred ";
        }
        //cout<<n<<endl;
        num = num%100;
        //cout<<num<<endl;
        if(num<20 && num>0) {
            res = res + digits[num] + " ";
            return;
        }
        n = num/10;
        if (n>0) {
            //cout<<"n"<<n<<endl;
            res = res + tens[n*10]+" ";
        }
        //cout<<num%10<<endl;
        if (num%10 !=0) {
            res = res + digits[num%10]+" ";
        }
        //cout<<res<<endl;
    }
};
