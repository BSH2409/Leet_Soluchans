class Solution {
public:
    bool canConstruct(string a, string b) {
        vector<int> hash(26,0);
        if(a.size()> b.size()) return false;
        for(int i=0;i<b.size();i++)
        {
            hash[b[i]-'a']++; if(i<a.size())hash[a[i]-'a']--;
        }
        for(auto i :hash)
        {
            if(i<0) return false;
        }
        return true;
    }
};