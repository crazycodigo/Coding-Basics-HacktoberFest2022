#!/usr/bin/env python
# coding: utf-8

# In[1]:


# script by: @minhadona 
# suggestions: minhadona@tuta.io

# the variables to authenticate on GMAIL are email_username and password


# In[7]:


#==============================================
#---- creating DF by webscraping the winners --
#==============================================
import requests
from bs4 import BeautifulSoup
import pandas as pd 

df = pd.DataFrame(columns=['mes', 'serie', 'premio', 'data_do_sorteio', 'n_sorteado', 'cupom_premiado','nome_ganhador'])
r = requests.get('https://company.ebit.com.br/concorra-premios/ultimos-ganhadores')
soup = BeautifulSoup(r.content, 'html.parser')

table = soup.find(id="table-striped")
for row in table.tbody.find_all('tr'):    
    # Find all data for each column
    columns = row.find_all('td')
    mes = columns[0].text.strip()
    serie = columns[1].text.strip()
    premio = columns[2].text.strip()
    data_do_sorteio = columns[3].text.strip()
    n_sorteado = columns[4].text.strip()
    cupom_premiado = columns[5].text.strip()
    nome_ganhador = columns[6].text.strip()

    df = df.append({'mes': mes,  'serie': serie, 'premio': premio, 'data_do_sorteio': data_do_sorteio, 'n_sorteado': n_sorteado, 'cupom_premiado': cupom_premiado, 'nome_ganhador':nome_ganhador}, ignore_index=True)


# In[8]:


#==============================================
#----------------- email funcion  -------------
#==============================================

import smtplib, ssl
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.header import Header
from email.utils import formataddr
import os
import logging

#port = 465  # For SSL
port = 465
smtp_server = "smtp.gmail.com"
sender_email = "ebit_webscraping@minhadona.com" # Enter your address
receiver_email = os.environ['EMAIL_USERNAME']  # Enter receiver address
password = os.environ['EMAIL_PASSWORD']
email_username = os.environ['EMAIL_USERNAME']
message = MIMEMultipart("alternative")
message["Subject"] = "-------------- resultados ebit --------------"
message["From"] = str(Header("RESULTADOS EBIT <resultados_ebit@minhadona.com>"))
message["To"] = receiver_email
        
  
def connect_and_send_email(plain_text, html_text):
      
    # Turn these into plain/html MIMEText objects
    part1 = MIMEText(plain_text, "plain")
    part2 = MIMEText(html_text, "html")

    # Add HTML/plain-text parts to MIMEMultipart message
    # The email client will try to render the last part first
    message.attach(part1)
    message.attach(part2)
    print('<password><'+password+'><username><'+email_username+'>')
    context = ssl.create_default_context()
    with smtplib.SMTP_SSL("smtp.gmail.com", 465, context=context) as server:
        server.ehlo()
        logged = server.login(email_username, password)
        sent = server.sendmail(sender_email, receiver_email, message.as_string())  
        logging.info(f'you are authenticated! return of server.login: {logged} type of server.login: {type(logged)}')
        logging.info(f'sent: {sent} type {(type(sent))}') 
        server.close()
        if isinstance(sent,dict):
            print('!email successfully sent!')
            logging.warning(' this forwards the whole available table; if you just want a sample, reassign the variable <df> to <df.head(n)> by n meaning the number of lines you want on your output table')
        


# In[ ]:


#==============================================
#---- html tabulating table + send on body ----
#==============================================

from pretty_html_table import build_table

html_table = build_table(df, 'green_dark')
connect_and_send_email(plain_text=html_table, html_text=html_table)