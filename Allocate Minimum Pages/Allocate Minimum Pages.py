class Solution:
    
    
    def isFeasible(self,arr,m,val):
        req = 1
        s = 0
        for i in range(len(arr)):
            if s + arr[i] > val:
                req += 1
                s = arr[i]
            else:
                s += arr[i]
                
        return req <= m
        
    def findPages(self,n,arr,m):
        if m > n:
            return -1
        maxPages = max(arr)
        sumofAllPages = sum(arr)
        low = maxPages
        high = sumofAllPages
        while low <= high:
            mid = (low+high)
            
            if self.isFeasible(arr,m,mid):
                res = mid
                high = mid - 1
            else:
                low = mid + 1
                
        return res
        



#{ 
 # Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):

        n = int(input())

        arr = [int(x) for x in input().strip().split()]
        m = int(input())

        ob = Solution()

        print(ob.findPages(n, arr, m))

# } Driver Code Ends