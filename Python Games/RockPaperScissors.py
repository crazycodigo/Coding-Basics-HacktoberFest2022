rock = '''
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
'''

paper = '''
    _______
---'   ____)____
          ______)
          _______)
         _______)
---.__________)
'''

scissors = '''
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
'''


choice=int(input("What do you chosse? Type 0 for Rock, 1 for Paper or 2 for Scissors.\n"))
if choice>=3 or choice<0:
  print("Well that's the wrong choice. Please select only 0 for rock, 1 for paper or 2 for scissors. :")
else:
  if choice==0:
    print(rock)
  elif choice==1:
    print(paper)
  elif choice==2:
    print(scissors)

  import random
  print("Computer Chose :")
  comp_choice=[rock,paper,scissors]
  comp_choice2=random.choice(comp_choice)
  if comp_choice2==rock:
    print(rock)
  elif comp_choice2==paper:
    print(paper)
  else:
    print(scissors)

  if (choice==0 and comp_choice2==rock) or (choice==1 and comp_choice2==paper) or (choice==2 and comp_choice2==scissors) :
    print("It's a draw")
  elif (choice==0 and comp_choice2==scissors) or (choice==1 and comp_choice2==rock) or (choice==2 and comp_choice2==paper):
    print("You Win")
  else:
    print("You Lose!!")
 
