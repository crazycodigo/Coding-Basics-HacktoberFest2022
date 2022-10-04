chance = 0
pt_user = 0
pt_com = 0
lst = ["Snake", "Water", "Gun"]
while chance<11:
    user = int(input("Choose:\n Snake[1]\t Water[2]\t Gun[3]"))
    import random
    comp = random.choice(lst)
    if user==2 and comp=="Gun":
        print(f"You chose {user} and computer chose {comp}\n So You win!!\n Points: You={pt_user}   Computer={pt_com}")
        chance += 1
        pt_user += 1
    elif user==3 and comp=="Snake":
        print(f"You chose {user} and computer chose {comp}\n So You win!!\n Points: You={pt_user}   Computer={pt_com}")
        chance += 1
        pt_user += 1
    elif user==1 and comp=="Water":
        print(f"You chose {user} and computer chose {comp}\n So You win!!\n Points: You={pt_user}   Computer={pt_com}")
        chance += 1
        pt_user += 1
    elif user==3 and comp=="Water":
        print(f"You chose {user} and computer chose {comp}\n So You lose!!\n Points: You={pt_user}   Computer={pt_com}")
        chance +=1
        pt_com +=1
    elif user==1 and comp=="Gun":
        print(f"You chose {user} and computer chose {comp}\n So You lose!!\n Points: You={pt_user}   Computer={pt_com}")
        chance +=1
        pt_com +=1
    elif user==2 and comp=="Snake":
        print(f"You chose {user} and computer chose {comp}\n So You lose!!\n Points: You={pt_user}   Computer={pt_com}")
        chance +=1
        pt_com +=1
    elif user==1 and comp=="Snake":
        print(f"You chose {user} and computer chose {comp}\n So Its a Tie!!\n Points: You={pt_user}   Computer={pt_com}")
        chance +=1
        pt_com +=0
        pt_user +=0
    elif user==2 and comp=="Water":
        print(f"You chose {user} and computer chose {comp}\n So Its a Tie!!\n Points: You={pt_user}   Computer={pt_com}")
        chance +=1
        pt_com +=0
        pt_user +=0
    elif user==3 and comp=="Gun":
        print(f"You chose {user} and computer chose {comp}\n So Its a Tie!!\n Points: You={pt_user}   Computer={pt_com}")
        chance +=1
        pt_com +=0
        pt_user +=0

print(f"Final Score:\n You={pt_user}\t Computer={pt_com}")
if pt_user==pt_com:
    print("Since Scores are same, ITS A TIE!!\n Better luck next time")
elif pt_user>pt_com:
    print("Since You score is more than the computer, YOU HAVE WON CONGRATS!!")
else:
    print("Since Computer's score is more than Your's, YOU HAVE LOST!!\n Better luck next time")
