class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int maxi=0;
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int i=0;
        while(n>=3 && i<n)
        {
            maxi+=piles[n-2];
            n-=2;
            i++;
        }
        return maxi;
    }
};