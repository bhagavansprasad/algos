a = [3,1,5,4,3]; k = 6
i = 0
for e in a[:]:
    print(i, e)
    if (i == 2):
        a.remove(e)
    i += 1
print(a)
