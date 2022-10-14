from tkinter import *
import random
import array
import smtplib, ssl
from email.message import EmailMessage
from email.mime.text import MIMEText
from tkinter import messagebox

class input_template():
    def __init__(self):
        self.window = Tk()
        self.window.title("Mail Sender")
    
        # take input
        Label(self.window, text="Length of userid/password : ").grid(row=1, column=1, sticky=W)
        Label(self.window, text="Your e-mail : ").grid(row=2, column=1, sticky=W)
        Label(self.window, text="receiver's mail : ").grid(row=3, column=1, sticky=W)
        Label(self.window, text="your password : ").grid(row=4, column=1, sticky=W)
        Label(self.window, text=None).grid(row=5, column=1, sticky=W)
        Label(self.window, text=None).grid(row=6, column=1, sticky=W)
        Label(self.window, text=None).grid(row=7, column=1, sticky=W)
        Label(self.window, text=None).grid(row=8, column=1, sticky=W)
        Label(self.window, text=None).grid(row=9, column=1, sticky=W)
        Label(self.window, text="Sent user_id : ").grid(row=10, column=1, sticky=W)
        Label(self.window, text="Sent password : ").grid(row=11, column=1, sticky=W)

        #make variable to store user input
        self.length = IntVar()
        self.sender_email = StringVar()
        self.receiver = StringVar()
        self.passw = StringVar()
        self.user_id = StringVar()
        self.password = StringVar()

        Entry(self.window, textvariable = self.length, justify=RIGHT).grid(row=1, column=2)
        Entry(self.window, textvariable = self.sender_email, justify=RIGHT).grid(row=2, column=2)
        Entry(self.window, textvariable = self.receiver, justify=RIGHT).grid(row=3, column=2)
        Entry(self.window, textvariable = self.passw, justify=RIGHT).grid(row=4, column=2)

        B = Button(self.window, text ="SEND", bd = '5', highlightcolor = 'blue', justify=CENTER,  command = self.output).grid(row=6, column=2)
        
        # Show output
    def output(self):
        try:
            length = self.length.get()
            sender_email = self.sender_email.get()
            receiver = self.receiver.get()
            passw = self.passw.get()
            
            DIGITS = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'] 
            LOCASE_CHARACTERS = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                                 'i', 'j', 'k', 'm', 'n', 'o', 'p', 'q',
                                 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
                                 'z']

            UPCASE_CHARACTERS = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                 'I', 'J', 'K', 'M', 'N', 'O', 'p', 'Q',
                                 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
                                 'Z']

            SYMBOLS = ['@', '#', '$', '%', '=', ':', '?', '.', '/', '|', '~', '>',
                       '*', '(', ')', '<']

            # combines all the character arrays above to form one array
            COMBINED_LIST = DIGITS + UPCASE_CHARACTERS + LOCASE_CHARACTERS + SYMBOLS

            # randomly select at least one character from each character set above
            rand_digit_pass = random.choice(DIGITS)
            rand_upper_pass = random.choice(UPCASE_CHARACTERS)
            rand_lower_pass = random.choice(LOCASE_CHARACTERS)
            rand_symbol_pass = random.choice(SYMBOLS)

            rand_digit_id = random.choice(DIGITS)
            rand_upper_id = random.choice(UPCASE_CHARACTERS)
            rand_lower_id = random.choice(LOCASE_CHARACTERS)
            rand_symbol_id = random.choice(SYMBOLS)
         
            temp_pass = rand_digit_pass + rand_upper_pass + rand_lower_pass + rand_symbol_pass
            temp_id   = rand_digit_id + rand_upper_id + rand_lower_id + rand_symbol_id

            for x in range(length - 4):
                temp_pass = temp_pass + random.choice(COMBINED_LIST)
                temp_id   = temp_id + random.choice(COMBINED_LIST)

                temp_pass_list = array.array('u', temp_pass)
                temp_id_list = array.array('u', temp_id)
                random.shuffle(temp_pass_list)
                random.shuffle(temp_id_list)

            password = ""
            user_id = ""
            for x in temp_pass_list:
                password = password + x
            for x in temp_id_list:
                user_id = user_id + x

            self.user_id = user_id
            self.password = password

            port = 465  # For SSL
            smtp_server = "smtp.gmail.com"
            msg=MIMEText("username: {}\npassword: {}".format(user_id, password))
            msg['Subject'] = "Random id and password"
            msg['From'] = sender_email
            msg['To'] = receiver
            context = ssl.create_default_context()
            with smtplib.SMTP_SSL(smtp_server, port, context=context) as server:
                server.login(sender_email, passw)
                server.sendmail(sender_email, receiver, msg.as_string())

            Label(self.window, text = user_id, font = 'Helvetica 12', justify=RIGHT).grid(row=10, column=2, sticky=E)
            Label(self.window, text= password, font = 'Helvetica 12', justify=RIGHT).grid(row=11, column=2, sticky=E)

        except smtplib.SMTPAuthenticationError:
            messagebox.showerror("Error", "invalid email or password\nor\nemail is not allowed for less secured apps")

        except UnboundLocalError:
            messagebox.showerror("Error", "length should be more than 4")


input_template()