# ECE 2524 Homework 2 Problem 3
# Thomas Elliott

amountOwed = 0
numberPeople = 0
maxAmount = 0
minAmount = 0

print "ACCOUNT SUMMARY"
with open('account.txt', 'r') as f:
    for line in f:
        #Get First name then format the line
        i = line.find(" ")
        firstName = line[0:i]
        line = line.lstrip(firstName)
        line = line.strip()
        
        #Get last name then format the line
        i = line.find(" ")
        lastName = line[0:i]
        line = line.lstrip(lastName)
        line = line.strip()
        
        #Get money owed then format the line
        i = line.find(" ")
        money = line[0:i]
        line = line.lstrip(money)
        line = line.strip()
        intMoney = float(money)
        #initializes minAmount to an existant value so that it can be compared to the rest of the amounts owed
        if minAmount == 0:
            minAmount = intMoney
        
        #Get city then format the line
        i = line.find(" ")
        city = line[0:i]
        line = line.lstrip(city)
        line = line.strip()
        
        #Get number
        line.rstrip()
        number = line
        
        amountOwed += intMoney
        numberPeople = numberPeople + 1
        
        if maxAmount < intMoney:
            maxAmount = intMoney
            maxOwer = lastName
            
        if minAmount > intMoney:
            minAmount = intMoney
            minOwer = lastName
            
    print "Total amount owed = ", amountOwed
    print "Average amount owed = ", amountOwed/numberPeople
    print "Maximum amount owed = ", maxAmount, "by", maxOwer
    print "Minimum amount owed = ", minAmount, "by", minOwer
        
