# Github username: parthbansal05
# Aim: creating a flask server which can be used to create a website using python and flask framework and threading
# Date: 5-10-2022
# start coding

import time
from flask import Flask, request, render_template
   
def webserver():
    app = Flask(__name__)
    @app.route('/home')
    def home():
        return render_template('home.html')

    @app.route('/form', methods=['POST'])
    def my_form_post():
        name=request.form['name']

        return render_template('res.html', name=name)

    app.debug = False
    app.run(host='127.0.0.1')

webserver()