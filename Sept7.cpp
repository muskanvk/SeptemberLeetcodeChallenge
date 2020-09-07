class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> c2s;
        unordered_map<string, char> s2c;
        vector<string> words;
        stringstream ss(str);
        string word;
        while(ss >> word)
            words.push_back(word);
        if(words.size() != pattern.length())
            return false;
        for(int i = 0; i < words.size(); i++) {
            if(s2c.empty() && c2s.empty()) {
                s2c[words[i]] = pattern[i];
                c2s[pattern[i]] = words[i];
            }
            else if(s2c.find(words[i])==s2c.end() && c2s.find(pattern[i])==c2s.end()) {
                s2c[words[i]] = pattern[i];
                c2s[pattern[i]] = words[i];
            }
            else if(c2s.find(pattern[i])==c2s.end() && s2c.find(words[i])!=s2c.end())
                return false;
            else if(c2s.find(pattern[i])!=c2s.end() && s2c.find(words[i])==s2c.end())
                return false;
            else {
                if(c2s[pattern[i]]==words[i] && s2c[words[i]]==pattern[i])
                    continue;
                else
                    return false;
            }
        }
        return true;
    }
};