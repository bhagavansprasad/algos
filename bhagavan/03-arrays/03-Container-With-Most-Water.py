class Solution:
    def maxArea(self, height: list[int]) -> int:
        area = 0
        narea = 0
        n = len(height)
        fp = 0
        rp = n-1
        i = 0
        while (True):
            fv = height[fp]
            rv = height[rp]
            base = rp - fp
            if (base == 0):
                base = 1
            if (fv < rv):
                minv = fv
                fp += 1
                
            else:
                minv = rv
                rp -= 1
            narea = minv * base
            if (narea >= area):
                area = narea

            if (fp >= rp):
                break
        return area

a = [1, 8, 6, 2, 5, 4, 8, 3, 7]
a = [1]
a = [1, 1]

s = Solution()
retval = s.maxArea(a)
print(retval)

            
