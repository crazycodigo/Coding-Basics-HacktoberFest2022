import requests
import json

def speak(str):
    from win32com.client import Dispatch
    speak=Dispatch("SAPI.SpVoice")
    speak.Speak(str)

url = ("you news api")
resp = requests.get(url).text

jos = json.loads(resp)

try:
    speak("The request was accepted ")
    speak("Top news of the day are:")
    arts = jos['articles']
    for article in arts:
        speak(article['title'])
        speak("Moving on to the next news.")
        
except Exception as e:
    speak("Sorry! the request was not accepted")