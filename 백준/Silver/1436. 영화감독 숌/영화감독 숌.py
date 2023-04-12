n = int(input())

cnt = 0
cur = 666
while 1 :
    if '666' in str(cur) :
        cnt += 1
    if cnt == n :
        print(cur)
        break
    cur += 1