def Shell_Sort(a):
   n = len(a)
   gap = n // 2

   while gap > 0:

       for i in range(gap, n):
           temp = a[i]
           j = i
           while j >= gap and a[j - gap] > temp:
               a[j] = a[j - gap]
               j -= gap
           a[j] = temp
       gap //= 2
   return a
    

def Insertion_Sort(a):
   for i in range(1, len(a)):

       key = a[i]
       j = i - 1
       while j >= 0 and key < a[j]:
           a[j + 1] = a[j]
           j -= 1
       a[j + 1] = key
   return a

def top_five_marks(marks):
    print("Top",len(marks),"Marks are : ")
    print(*marks[::-1], sep="\n")

marks=[]
n = int(input("Enter number of students whose marks are to be displayed : "))
print("Enter marks for",n,"students (Press ENTER after every students marks): ")
for i in range(0, n):
    ele = int(input())
    marks.append(ele)  # adding the element

print("The marks of",n,"students are : ")
print(marks)

flag=1;
while flag==1:
    print("\n---------------MENU---------------")
    print("1. Insertion of the marks")
    print("2. Shell Sort of the marks")
    print("3. Exit")
    ch=int(input("\n\nEnter your choice (from 1 to 3) : "))

    if ch==1:
        Insertion_Sort(marks)
        a=input("\nDo you want to display top marks from the list (yes/no) : ")
        if a=='yes':
            top_five_marks(marks)
        else: 
            flag=0

    elif ch==2:
        Shell_Sort(marks)
        a = input("\nDo you want to display top five marks from the list (yes/no) : ")
        if a == 'yes':
            top_five_marks(marks)
        else:
            flag = 0

    elif ch==3:
        flag=0

    else:
        print("\nEnter a valid choice!!")
        flag=0


