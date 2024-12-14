netAmount = 0  # Global variable for the balance

def deposit():
    global netAmount  # Indicate that we are using the global netAmount
    amount = int(input("Enter amount to deposit: "))
    netAmount += amount
    print("Balance = ", netAmount)
    return netAmount

def withdraw():
    global netAmount  # Indicate that we are using the global netAmount
    amount = int(input("Enter amount to withdraw: "))
    if amount <= netAmount:
        netAmount -= amount
        print("Balance = ", netAmount)
    else:
        print("Insufficient balance!")
    return netAmount

def Total_balance():
    return netAmount

flag = 1
while flag == 1:
    print("\n---------Menu----------\n")
    print("1. Deposit")
    print("2. Withdraw")
    print("3. Total Balance")
    print("4. Exit")
    
    try:
        ch = int(input("Enter your choice: "))  # Input validation
    except ValueError:
        print("Invalid input! Please enter a number.")
        continue

    if ch == 1:
        deposit()  # Call the deposit function
        a = input("Do you want to continue (yes/no): ")
        if a.lower() != "yes":
            print("Total balance:", Total_balance())  # Print the total balance
            flag = 1
    elif ch == 2:
        withdraw()  # Call the withdraw function
        a = input("Do you want to continue (yes/no): ")
        if a.lower() != "yes":
            print("Total balance:", Total_balance())  # Print the total balanc
            flag = 1
    elif ch == 3:
        print("Total balance:", Total_balance())  # Print the total balance
        a = input("Do you want to continue (yes/no): ")
        if a.lower() != "yes":
            flag = 1
    elif ch == 4:
        flag = 0  # Exit the loop
    else:
        print("Wrong choice")
        a = input("Do you want to continue (yes/no): ")
        if a.lower() != "yes":
            flag = 1
