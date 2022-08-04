pt=input('Enter the plain text ')
key=int(input('Enter the depth '))
res = [[' ' for i in range(0,len(pt))] for j in range(key)]
temp=1
r,c=0,0
for i in pt:
    res[r][c] = i
    c+=1
    if(temp==1):
        r+=1
        if(r>=key-1):
            temp=0
    else:
        r-=1
        if(r<=0):
            temp=1
enc=res
for i in range(key):
  print("".join(enc[i]))
print("\n")
for i in range(key):
    for j in range(0,len(pt)):
        if(res[i][j]!=' '):
            print(res[i][j],end="")
dec = []
r,c=0,0
print("\n")
for i in range(len(pt)):
    dec.append(res[r][c])
    c+=1
    if(temp==1):
        r+=1
        if(r>=key-1):
            temp=0
    else:
        r-=1
        if(r<=0):
            temp=1
dec=str(dec)
print(str(dec))
