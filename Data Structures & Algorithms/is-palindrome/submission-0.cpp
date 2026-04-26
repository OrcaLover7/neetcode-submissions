class Solution {
public:

    //immediate thought - just match characters from each side
    //missed basic - ignore non-alphanumberic chars
    //need to clean up the string first
    bool isPalindrome(string s) {

        int n = s.size();

        string cleaned = "";

        for(auto c : s){
            if(isalnum(c)) cleaned += tolower(c);
        }

        n = cleaned.size();
        for(int i = 0; i < n/2; i++)  {
            if(cleaned[i] != cleaned[n-1-i])
                return false;
        }
        
        return true;
    }
};
