print("\nWelcome to the game - GUESS THE NUMBER.\n "
          "In this game you have to guess the number by trial and error method but remember you have only 9 guesses :]\n")

n=18
c = 1

while(c<=9):
    a = int(input("Please enter your guess: \n"))
    if a > 18:
        print("Please guess a number which is lesser")
    elif a < 18:
        print("Please guess a number which is greater")
    else:
        print("Congrats, You Won")
        print("No. of guesses you took to win = " , c )
        break
    print("No. of guesses left= " , 9-c)
    c = c+1

if c > 9:

    print("Game over")