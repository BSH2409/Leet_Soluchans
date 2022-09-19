class Solution:
    def removeInvalidParentheses(self,s):

        del_left=0
        del_right=0
        
        for i in s:
            if i=="(":
                del_left+=1
            elif i==")":
                if del_left>0:
                    del_left-=1
                else:
                    del_right+=1
        
        ans=set()
        
        def dfs(index,left,right,del_left,del_right,seq):
            if index==len(s):
                if left==right and del_left==0 and del_right==0:
                    ans.add(seq)
                return 
            
            if s[index]=='(':
                if del_left>0:
                    dfs(index+1,left,right,del_left-1,del_right,seq)
                    
                dfs(index+1,left+1,right,del_left,del_right,seq+"(")
                
            elif s[index]==')':
                if del_right>0:
                    dfs(index+1,left,right,del_left,del_right-1,seq)
                if  right<left:  
                    dfs(index+1,left,right+1,del_left,del_right,seq+")")
            else:
                dfs(index+1,left,right,del_left,del_right,seq+s[index])
                
                    
                
        dfs(0,0,0,del_left,del_right,"")
        return list(ans)