class Solution {
public:
    bool isAnagram(string s, string t) {
        //if character counts of the 2 strings are same, return true if not false;

        if(s.size() != t.size()) return false;

        unordered_map<char, int> count1, count2;

        for(auto& c : s){
            count1[c]++;
        }

        for(auto& c : t){
            count2[c]++;
        }


        if(count1.size() != count2.size()) return false;

        for(auto [c, count] : count1){
            if(count2.count(c))
            {
                if(count != count2[c])
                    return false;
                else
                    count2.erase(c);
            }
            else
                return false;
        }

        if(count2.size()) return false;

        return true;
        
    }
};
