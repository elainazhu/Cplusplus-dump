import random
import time

start_time = time.time()
score = 0

while(time.time()<start_time+60):
    score +=1
    sign = random.randint(0,2)
    if sign == 0:
        x = random.randint(0,200)
        y = random.randint(0,200)
        z = int(input( str(x) + " + " + str(y) + ": "))
        while ( z != x+y ):
            z = int(input( str(x) + " + " + str(y) + ": "))
    if sign == 1:
        x = random.randint(0,200)
        y = random.randint(0,200)
        if(y>x):
            xx=x
            x=y
            y=xx
        z = int(input( str(x) + " - " + str(y) + ": "))
        while ( z != x-y ):
            z = int(input( str(x) + " - " + str(y) + ": "))
    if sign == 2:
        x=100
        y=100
        while(x*y>1000):
            x = random.randint(0,200)
            y = random.randint(0,20)
        z = int(input( str(x) + " x " + str(y) + ": "))
        while ( z != x * y ):
            z = int(input( str(x) + " x " + str(y) + ": "))
    print("time: ", end=' ')
    print(int(time.time()-start_time))

print( "SCORE: " + str(score))
