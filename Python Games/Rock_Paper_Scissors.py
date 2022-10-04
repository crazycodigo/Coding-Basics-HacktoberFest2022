from pickle import TRUE
import random
# Rock(R) Paper(P) Scissors(S)
pp=0
cp=0
def game(comp,player):

    if comp=='r' :
        if player=='p':
            print("Player Wins 🎉..don't get too happy that was a throw 😛😏")
            return 'p'
        elif player=='r':
            print("Draw 🥱😴")
            return 'd'
        elif player=='s':
            print("You Lose ... NOOB can't even beat a bot 😂😆")
            return 'c'

    elif comp=='p' :
        if player=='s':
            print("Player Wins 🎉..don't get too happy that was a throw 😛😏")
            return 'p'
        elif player=='p':
            print("Draw 🥱😴")
            return 'd'
        elif player=='r':
            print("You Lose ... NOOB can't even beat a bot 😂😆")
            return 'c'

    elif comp=='s' :
        if player=='r':
            print("Player Wins 🎉..don't get too happy that was a throw 😛😏")
            return 'p'
        elif player=='s':
            print("Draw 🥱😴")
            return 'd'
        elif player=='p':
            print("You Lose ... NOOB can't even beat a bot 😂😆")
            return 'c'


keys =1
while keys:      

    print("Computer's turn - Rock(r) Paper(p) Scissors(s) ")
    print("Comp can choose its input idiot ...enter yours now")
    RandNo=random.randint(1,3)
    if RandNo ==1:
        comp= 'r' 
    elif RandNo ==2:
        comp= 'p' 
    elif RandNo ==3:
        comp= 's' 
    player=input("Player's turn - Rock(r) Paper(p) Scissors(s) ")
    res = game(comp,player)
    if res == 'p': pp+=1
    elif res == 'c' :cp+=1
    if pp>=3 or cp>=3:
        keys=0
    print (pp, cp )
if pp>cp:
    print("you were lucky  you won the game")
elif cp>pp:
    print("LOL NOOB you just lost 3 rounds to a BOT ...please DIE..U're a BURDEN on EARth 🙂 <3 ")