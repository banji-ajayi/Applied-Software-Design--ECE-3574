# ECE 2524 Homework 2 Problem 2
# Thomas Elliott
print "ACCOUNT INFORMATION FOR BLACKSBURG RESIDENTS"
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
        
        #Get city then format the line
        i = line.find(" ")
        city = line[0:i]
        line = line.lstrip(city)
        line = line.strip()
        
        #Get number
        line.rstrip()
        number = line
        
        if city == "Blacksburg":
            print ", ".join([number, lastName, firstName, money])
        
