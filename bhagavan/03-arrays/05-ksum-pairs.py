class Solution:
    def maxOperations(self, nums: list[int], k: int) -> int:
        n = len(nums)
        htable = {}
        count = 0

        for e in nums[:]:
            v = k - e
            if k <= v:
                v = abs(v)

            #print(f"e: {e}, k :{k}, v :{v}, count :{count}, nums :{nums}, htable :{htable}")
            if (v in htable):
                count += 1
                nums.remove(e)  
                nums.remove(htable[v])  
                del htable[v]
            else:
                htable[e] = e
            #print(f"e: {e}, k :{k}, v :{v}, count :{count}, nums :{nums}, htable :{htable}")
            #print()
        #print(f"k :{k}, count :{count}, nums :{nums}, htable :{htable}")
        return (count)

        
data = [
        {'k': 5, 'exp': 2, 'a': [1,2,3, 4]},
        {'k': 6, 'exp': 1, 'a': [3,1,3,4,3]},
        {'k': 1, 'exp': 0, 'a': [3,1,5,1,1,1,1,1,2,2,3,2,2]},
        {'k': 4, 'exp': 4, 'a': [2,5,4,4,1,3,4,4,1,4,4,1,2,1,2,2,3,2,4,2]},
]

d = Solution()

for ele in data:
    a = ele['a']
    k = ele['k']
    exp = ele['exp']

    retval = d.maxOperations(a, k)

    if (retval != exp):
        print(f"FAILED : exp :{exp}, retval :{retval}, a :{a}")
    else:
        print(f"SUCCESS: exp :{exp}, retval :{retval}, a :{a}")


