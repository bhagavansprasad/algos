class Solution:
    def longestOnes(self, nums: list[int], k: int) -> int:
        n = len(nums)
        print(nums)
        sp = fp = 0
        t = k
        count = 0
        big = 0
        c = 0

        while(fp < n):
            # print(f"S: k :{k}, t :{t}, v :{nums[fp]}, fp :{fp}, count :{count}, big :{big}")
            prev = count

            if (nums[fp] == 1):
                count = count + 1
            elif (nums[fp] == 0  and t > 0):
                count = count + 1
                t = t - 1
            else:
                if (count > big):
                    big = count
                # print(f"k :{k}, t :{t}, v :{nums[fp]}, fp :{fp}, count :{count}, big :{big}")
                count = 0
                fp = fp - 1
                t = k
                print()
           
            print(f"E: k :{k}, t :{t}, v :{nums[fp]}, fp :{fp}, count :{count}, big :{big}")
            fp = fp + 1
        return big   
            
        return count
        
        
data = [
        {'k': 2, 'exp': 6, 'a': [1,1,1,0,0,0,1,1,1,1,0]},
                               #[1,1,1,0,0,1,1,1,1,1,1]
                               #           -         -
        #{'k': 3, 'exp': 10, 'a': [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]},
                                #[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]                                
                                #         - -       -
]

def main():
    d = Solution()

    for ele in data:
        a = ele['a']
        k = ele['k']
        exp = ele['exp']
                
        retval = d.longestOnes(a, k)
        if (retval != exp):
            print(f"FAILED : k :{k}, exp :{exp}, retval :{retval}, a :{a}")
        else:
            print(f"SUCCESS: k :{k}, exp :{exp}, retval :{retval}, a :{a}")
        print()


if __name__ == "__main__":
    main()