import matplotlib.pyplot as plt
import numpy as np

# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
def solution1(buckets):
    # Implement your solution here
    bes = 0
    for a in buckets:
        if a == 'B':
            bes += 1

    if bes > (len(buckets)/2)+1:
        return -1
    
    max = 0
    aux = buckets[0::2]
    for a in aux:
        if a == 'B':
            max += 1

    div = (bes-max)
    if max < div:
        half = buckets[1::2]
        if bes < len(half):
            maxc = 0
            maxb = 0
            c = 0
            b = 1
            for i in range(0, len(half)):
                if half[i] == '.':
                    c +=1
                if half[i] == 'B':
                    if maxc < c and c < bes:
                        maxc = c
                        b += 1
                        maxb = b 
                    elif c > bes:
                        c = 0
                        b = 1
            
            if maxc < bes-maxb:
                return bes-maxb
            else:
                return bes-1

    half = buckets[0::2]
    if bes < len(half):
        maxc = 0
        maxb = 0
        c = 0
        b = 1
        for i in range(0, len(half)):
            if half[i] == '.':
                c +=1
            if half[i] == 'B':
                if maxc < c and c < bes:
                    maxc = c
                    b += 1
                    maxb = b 
                elif c > bes:
                    c = 0
                    b = 1
        
        if maxc < bes-maxb:
            return bes-maxb
        else:
            return bes-1

def solution2(buckets):
	bes = 0
	for a in buckets:
		if a == 'B':
			bes += 1
	
	if (len(buckets)+1)/2 < bes:
		return -1
		
	


print("Problema: devolver el número de pasos necesarios para separar las Bs de una lista a distancia de 2 huecos exactos cada una, y devolver -1 sino se puede")
buc = ['B','B','B','B','B','.','.','.','.']
