import numpy

elf_array = []
total_cal = 0

with open("D1/d1.txt","r") as file:
    lines = file.readlines()

for line in lines:
    if(line != '\n'):
        total_cal += int(line)
    else:
        elf_array.append(total_cal)
        total_cal = 0


int_array = numpy.array(elf_array, dtype=numpy.int)

int_array.sort()

print(int_array[-1]+int_array[-2]+int_array[-3])



