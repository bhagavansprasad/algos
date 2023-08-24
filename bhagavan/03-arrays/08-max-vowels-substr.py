class Solution:
    def isvowel(self, ch):
        if ch in "aeiou":
            return True
        return False
        
    def maxVowels(self, s: str, k: int) -> int:
        c = vc = max_vowels = 0
        n = len(s)
        
        if (k == 1):
            for ch in s:
                if (self.isvowel(ch)):
                    return 1
            return 0
        
        sp = fp = 0
        for fp in range(k):
            if(self.isvowel(s[fp])):
                vc += 1
        max_vowels = vc
        # print(f"k :{k}, sp :{sp}, fp :{fp}, vc:{vc}, max_vowels :{max_vowels}")
        
        for fp in range(fp+1, n):
            if(self.isvowel(s[fp])):
                vc += 1

            if(self.isvowel(s[sp])):
                vc -= 1
            
            sp = sp + 1
            if (vc > max_vowels):
                max_vowels = vc
            # print(f"k :{k}, sp :{sp}, fp :{fp}, vc:{vc}, max_vowels :{max_vowels}")
        
        return max_vowels

data = [
        {'k': 1, 'exp': 1, 'a': 'abcdef'},
        {'k': 3, 'exp': 2, 'a': 'abcidef'},
        {'k': 3, 'exp': 3, 'a': 'abciiidef'},
        {'k': 2, 'exp': 2, 'a': 'aeiou'},
        {'k': 3, 'exp': 2, 'a': 'leetcode'},
        {'k': 7, 'exp': 4, 'a': 'weallloveyou'},
]

d = Solution()

for ele in data:
    a = ele['a']
    k = ele['k']
    exp = ele['exp']

    # print(ele)
    
    retval = d.maxVowels(a, k)
    if (retval != exp):
        print(f"FAILED : k :{k}, exp :{exp}, retval :{retval}, a :{a}")
    else:
        print(f"SUCCESS: k :{k}, exp :{exp}, retval :{retval}, a :{a}")
    print()


