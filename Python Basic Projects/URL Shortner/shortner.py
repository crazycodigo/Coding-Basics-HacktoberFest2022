import urllib
import requests
key = '5819804......9fb9030' #put Your API key
url = urllib.parse.quote('https://www.youtube.com/') #link you want to shorten
name  = 'shivrajjjj' #put your preffered name
r = requests.get('http://cutt.ly/api/api.php?key={}&short={}&name={}'.format(key, url, name))
print(r.text)
