num = input()
num = int(num)
l = []
for i in range(num):
  name, day, month, year = input().split()
  l.append((name, int(day), int(month), int(year)))
  l.sort(key=lambda x: (x[3], x[2], x[1]))

print(l[-1][0])
print(l[0][0])
