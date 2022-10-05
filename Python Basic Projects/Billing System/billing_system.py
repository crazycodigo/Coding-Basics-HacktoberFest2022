total = 0
while (True):
	userInput = input("Enter the item price or press q to quit: \n")
	if (userInput!='q'):
		total = total + int(userInput)
		print(f"Order total so far: ₹{total}")
	else:
		print(f"Your Bill total is ₹{total}. Thanks for shopping with us")
		break