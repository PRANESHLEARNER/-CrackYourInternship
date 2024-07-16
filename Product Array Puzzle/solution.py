#User function Template for python3

class Solution:
    def productExceptSelf(self, nums, n):
         if n == 1:
           return[1]
           
           left_product = [0] * n
           right_product = [0] * n
           
           left_product[0] = 1
           right_product[n-1] = 1
           
           for i in range(1,n):
               left_product[i] = left_product[i-1] * nums[i-1]
               
            for i in range(n-2, -1, -1):
                right_product[i] = right_product[i+1] * nums[i+1]
                
            p = [0] * n
            for i in range(n):
                p[i] = left_product[i] * right_product[i]
                
            return p
        #code here


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t=int(input())

    for _ in range(t):
        n=int(input())
        arr=[int(x) for x in input().split()]

        ans=Solution().productExceptSelf(arr,n)
        print(*ans)
# } Driver Code Ends