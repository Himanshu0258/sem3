
def avgScore(mark):
    Total = 0
    for i in mark:
        Total = Total+i

    return Total/len(mark)


def maxScore(mark):
    max = mark[0]
    for m in mark:
        if m > max:
            max = m
    return max


def minScore(mark):
    min = mark[0]
    for i in mark:
        if i < min:
            min = i
    return min


def countAbsent(mark):
    count = 0
    for i in mark:
        if i == 0:
            count = count+1

    return count


def freqMax(mark):
    max = 0
    element = maxScore(mark)
    for i in mark:
        freq = mark.count(i)
        if(freq > max):
            max = freq
            element = i
    res = [max, element]
    return res


# Main
N = int(input("Enter no. of students: "))
print("Note: If student is absent then add marks = 0")
Marks = []

for i in range(0, N):
    mark = float(input("Enter "+str(i+1)+" student FDS marks : "))
    Marks.append(mark)


# Menu
flag = 1
while flag == 1:
    print("\n---------Menu----------")
    print("\n\n1) Average Score of Class: \n2) Highest score and lowest score of class \n3) Students who were absent for the test \n4) Max frequency \n5) Exit")
    ch = int(input("\nEnter choice: "))

    if ch == 1:
        avg = avgScore(Marks)
        print("Avg Score of Class = "+str(avg))

    elif ch == 2:
        print("\nHigh Score of Class: "+str(maxScore(Marks)))
        print("\nMin Score of Class: "+str(minScore(Marks)))

    elif ch == 3:
        print("\nNo. of Students who were absent for the test : " +
              str(countAbsent(Marks)))

    elif ch == 4:
        print("\nDisplay mark with highest frequency")
        print("\nMarks: " + str(freqMax(Marks)[1])
              + " with frequency " + str(freqMax(Marks)[0]))
    else:
        flag = 0