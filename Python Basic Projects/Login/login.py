dict = {'shiv': 'shiv12345', 'raj': 'raj12345', 'rohan': 'rohan12345'}

username = input("enter your username: ")

if username in dict:
    password = input("Please enter you password: ")

    if dict[username]==password:
        print("You have successfully logged in !!")
    
    else:
        print("Invalid passeword !!")

else:
    print("You are not a valid user !!")