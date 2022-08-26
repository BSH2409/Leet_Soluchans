class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string ns = to_string(n);
        sort(ns.begin(),ns.end());
        
        for(int i =1;i<= 1e9 ; i*=2)
        {
            string t= to_string(i);
            sort(t.begin(),t.end());
            if(ns==t) return true;
        }
        
        return false;
    }
};