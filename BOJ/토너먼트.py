total_num, jimin, hansu = map(int, input().split())

if jimin > hansu:
  jimin, hansu = hansu, jimin

num = 0

while (jimin != hansu):
  jimin -= jimin // 2
  hansu -= hansu // 2
  num += 1
print(num)