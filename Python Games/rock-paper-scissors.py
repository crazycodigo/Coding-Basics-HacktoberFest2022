from random import randint
#This is a single player Player V. Computer Rock Paper Scissors game made with python
opts = ["Rock", "Paper", "Scissors"]

computer = opts[randint(0,2)]

player = False
while player == False:
    player = input("What's your pick? [Rock, Paper, Scissors]: ")
    if player == computer:
        print("\nThats a draw!")
    elif player == "Rock":
        if computer == "Paper":
            print("\nPlayer loses this.", computer, "covers", player)
        else:
            print("\nPlayer wins!", player, "smashes", computer)
    elif player == "Paper":
        if computer == "Scissors":
            print("\nPlayer lost...", computer, "cut", player)
        else:
            print("\nPlayer wins!", player, "covers", computer)
    elif player == "Scissors":
        if computer == "Rock" :
            print("\nPlayer lost.", computer, "smashes", player)
        else:
            print("\nPlayer wins! ", player, "cut", computer)
    else:
        print("\nInvalid choice, please check the spelling.")

    player = True
    computer = opts[randint(0,2)]
