# -*- coding: utf-8 -*-
"""백준 초오오오오급2-1.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1X2A8jxt_hymXHAwAtTw5FXjLwPitIwGh
"""

#11655
word = input()
change = ''

for i in word:
  if ord(i) >= 65 and ord(i) <91:
    a = ord(i) + 13
    if ord(i) > 90-13:
      i = chr(a - 26)
    else:
      i = chr(a)
    change += i
  elif ord(i) >= 97 and ord(i) <123:
    a = ord(i) + 13
    if ord(i) > 122-13:
      i =chr(a - 26)
    else:
      i = chr(a)
    change += i
  else :
    change += i
    
print(change)

#17283
L = int(input())
R = int(input())
length = L*R//100
bri =2
total = 0

while length > 5:
  total = total + length * bri
  length = length*R//100
  bri = bri *2
  
print(total)

#17284
money = 5000
a = input().split()

for i in a:
  if i =='1':
    money -= 500
  elif i == '2':
    money -= 800
  elif i == '3':
    money -= 1000
    
print(money)

#17285
a = input()
c = ''
key = ord(a[0]) ^ ord('C')

  
for j in a:
  j = chr(ord(j) ^ key)
  c += j
  
print(c)

#XOR연산은 역연산도 XOR

#17288
a = list(input())
a = list(map(int,a)) + [13]
b = 0
c = 0

for i in range(len(a)-1):
  if a[i] + 1 == a[i + 1]:
    b +=1
  else:
    if b == 2:
      c += 1
      b = 0
    elif b >2:
      b = 0
      
print(c)

