total=0
while True:
	ch= input("enter y to enter price/ any other key to quit)
	if (ch=='y'):
    amount= int(input("enter price"))
		total = total + amount
		print("Order total so far: ₹", total")
	else:
		print("Your Bill total is ₹" total ". Thanks for shopping with us")
		break
