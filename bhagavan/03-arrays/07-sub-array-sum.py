class Solution:
    def findMaxAverage(self, nums: list[int], k: int) -> float:
        n = len(nums)
        sp = 0 
        fp = 0
        s = 0
        t = avg = nums[0] 
        
        if (k == 1):
            for fp in range(1, n):
                if (nums[fp] > avg):
                    avg = nums[fp]
            return avg
        
        for fp in range(k):
            s = s + nums[fp]
            
        t = avg = s / k
        
        # print(f"k :{k}, sp :{sp:>5}, fp :{fp:>5}, s:{s:>5}, t :{t:>5}, avg :{avg :>5}")
        for fp in range(fp+1, n):
            s = s + nums[fp]
            s = s - nums[sp]
            sp = sp + 1
               
            t = s / k
            
            if (t > avg):
                avg = t
            # print(f"k :{k}, sp :{sp:>5}, fp :{fp:>5}, s:{s:>5}, t :{t:>5}, avg :{avg :>5}")
        return avg

data = [
        {'k': 4, 'exp': 12.75000, 'a': [1,12,-5,-6,50,3]},
        {'k': 1, 'exp': 5, 'a': [5]},
        {'k': 1, 'exp': -1, 'a': [-1]},
        {'k': 5, 'exp': 2.80000, 'a': [4,0,4,3,3]},
        {'k': 1, 'exp': 4, 'a': [0,4,0,3,2]},
        {'k': 1, 'exp': 9, 'a': [2,7,3,4,9,4,9,2,4,7]},
]

d = Solution()

for ele in data:
    a = ele['a']
    k = ele['k']
    exp = ele['exp']

    # print(ele)
    
    retval = d.findMaxAverage(a, k)
    if (retval != exp):
        print(f"FAILED : exp :{exp}, retval :{retval}, a :{a}")
    else:
        print(f"SUCCESS: exp :{exp}, retval :{retval}, a :{a}")
    print()


