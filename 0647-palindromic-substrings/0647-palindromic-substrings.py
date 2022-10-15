class Solution:
    def countSubstrings(self, s: str) -> int:
        
        res = 0
        
        def help(left, right):
            count=0
            while 0 <= left < len(s) and 0 <= right < len(s) and s[left] == s[right]:                
                count += 1
                left -= 1
                right += 1        
            return count
        
        i,n=0, len(s)
        while i<n:
            start=i
            i+=1
            while i<n and s[start]==s[i]:
                i+=1
            repeats =i-start
            res+= repeats *(repeats+1) /2
            res+= help(start-1,i)
            
        return int(res)