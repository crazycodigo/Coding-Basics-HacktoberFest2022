import pytube
from pytube import YouTube

path = input("enter the path where you want to save the video: ")
link = input("enter the correct url of the youtube video: ")
youtube = pytube.YouTube(link)
video = youtube.streams.first()
video.download(path)