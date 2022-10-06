import email
from enum import unique
from app import db
from flask_login import UserMixin

class User(UserMixin,db.Model):
    __tablename__="user"

    id=db.Column(db.Integer,primary_key=True)
    username=db.Column(db.String(80), unique=True, nullable=False)
    email=db.Column(db.String(120), unique=True, nullable=False)
    pwd=db.Column(db.String(300), unique=True, nullable=False)

    def __repr__(self):
        return '<User %r>' %self.username