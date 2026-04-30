class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& v) {
        
        // unordered_map<string, vector<string>> mp;

        // for(auto& s : strs){
        //     vector<int> freq(26, 0);

        //     for(auto &c : s){
        //         freq[c - 'a']++;
        //     }

        //     string key_string = "";

        //     for(int i = 0; i < 26; i++){
        //         key_string += ("-" + to_string(freq[i]));
        //     }

        //     mp[key_string].push_back(s);
        // }

        // vector<vector<string>> ans;

        // for(auto &[s, arr] : mp)
        //     ans.push_back(arr);
        

        // return ans;
        map<map<char, int>, vector<string>> anagrams;

        for(auto& str : v){
            map<char, int> freq_map;

            for(char c : str){
                freq_map[c]++;
            }

            anagrams[freq_map].push_back(str);
        }

        vector<vector<string>> ans;

        for(auto& [_, anagram_list] : anagrams) ans.push_back(anagram_list);
        
        return ans;
    }
};
