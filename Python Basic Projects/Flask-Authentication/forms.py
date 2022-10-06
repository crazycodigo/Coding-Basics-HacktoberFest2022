from ast import Pass, Str
from wtforms import (
    StringField,
    PasswordField,
    BooleanField,
    IntegerField,
    DateField,
    TextAreaField
)

from flask_wtf import FlaskForm
from wtforms.validators import InputRequired,Length, EqualTo, Email,Regexp,Optional
import email_validator
from flask_login import current_user
from wtforms import ValidationError,validators
from models import User

class login_form(FlaskForm):
    email=StringField(validators=[InputRequired(),Email(),Length(1,64)])
    pwd=PasswordField(validators=[InputRequired(),Length(min=8,max=72)])
    username=StringField(
        validators=[Optional()]
    )
class register_form(FlaskForm):
    username=StringField(
        validators=[InputRequired(),Length(3,20,message="Please enter valid username"),Regexp(
            "^[A-Za-z][A-Za-z0-9_.]*$",0,"Usernames contain only letters," "number, dot or underscore",
        ),
        ]
    )
    email=StringField(validators=[InputRequired(),Email(),Length(1,64)])
    pwd=PasswordField(validators=[InputRequired(),Length(8,72)])
    cpwd=PasswordField(
        validators=[InputRequired(),Length(8,72),EqualTo("pwd",message="Password should match"),]
    )

    def validate_email(self,email):
        if User.query.filter_by(email=email.data).first():
            raise ValidationError("Already registered")
    def validate_uname(self,uname):
        if User.query.filter_by(username=username.data).first():
            raise ValidationError("Username not available")