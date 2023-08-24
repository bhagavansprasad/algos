class Solution:
    def maxOperations(self, nums: list[int], k: int) -> int:
        n = len(nums)
        htable = {}
        count = 0

        for e in nums:
            if(e in htable):
                htable[e] += 1
            else:
                htable[e] = 1

        # print(f"k: {k}, nums :{nums}, htable :{htable}")
        for e in list(htable.keys()):
            v = k - e
            if k <= v:
                v = abs(v)
            if (v in htable):
                pairv = htable[v]
                if e+e == k:
                    count += htable[e]//2
                else:
                    count = count + min(pairv, htable[e])
                del htable[e]
                if (v in htable):
                    del htable[v]

        # print()
        return (count)


        
data = [
        {'k': 5, 'exp': 2, 'a': [1,2,3, 4]},
        {'k': 6, 'exp': 1, 'a': [3,1,3,4,3]},
        {'k': 1, 'exp': 0, 'a': [3,1,5,1,1,1,1,1,2,2,3,2,2]},
        {'k': 3, 'exp': 4, 'a': [2,5,4,4,1,3,4,4,1,4,4,1,2,1,2,2,3,2,4,2]},
]

d = Solution()

for ele in data:
    a = ele['a']
    k = ele['k']
    exp = ele['exp']

    # print(ele)
    
    retval = d.maxOperations(a, k)
    if (retval != exp):
        print(f"FAILED : exp :{exp}, retval :{retval}, a :{a}")
    else:
        print(f"SUCCESS: exp :{exp}, retval :{retval}, a :{a}")


