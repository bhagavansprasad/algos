import time

I2RMap = {
        1:'I',
        2:'II',
        3:'III',
        4:'IV',
        5:'V',
        6:'VI',
        7:'VII',
        8:'VIII',
        9:'IX',
        10:'X',
        40:'XL',
        50:'L',
        90:'XC',
        100:'C',
        400:'CD',
        500:'D',
        900:'CM',
        1000:'M',
        }

RomanList = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]

class Solution:
    def intToRoman(self, num: int) -> str:
        values = {1:0, 4:0, 5:0, 9:0, 10:0, 40:0, 50:0, 90:0, 100:0, 400:0, 500:0, 900:0, 1000:0}
        romstr = ""
        i = 0

        while(num):
            for i in RomanList:
                r = num%i
                q = num//i
                if (r == num):
                    continue
                #time.sleep(1)
                values[i] += q
                #print(f"num :{num :>5}, i: {i:>5}, r :{r :>5}, q :{q}, values :{values}")
                num = r
                if (num <= 0):
                    break
        for key in values:
            for i in range(values[key]):
                romstr = I2RMap[key] + romstr

        #print(f"romstr :{romstr}")
        return romstr
                


ipdata = [1994, 58, 3, 3400, 3999]
d = Solution()
for i in ipdata:
    print(f"{i :>5}: {d.intToRoman(i)}")
            
        
