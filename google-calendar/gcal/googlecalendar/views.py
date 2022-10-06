import os
import google_apis_oauth
from googleapiclient.discovery import build
from django.shortcuts import HttpResponseRedirect,HttpResponse,render
from django.http import JsonResponse
from google_apis_oauth import InvalidLoginException
# to allow htttp calls
os.environ['OAUTHLIB_INSECURE_TRANSPORT'] = '1'
# redirect link for google
REDIRECT_URI = 'http://localhost:8000/rest/v1/calendar/redirect'
# required scopes
SCOPES = ['https://www.googleapis.com/auth/calendar']
JSON_FILEPATH = os.path.join(os.getcwd(), 'token.json')
# home page
def home(request):
    return render(request,'open.html')

def GoogleCalendarInitVIew(request):
    oauth_url = google_apis_oauth.get_authorization_url(
        JSON_FILEPATH, SCOPES, REDIRECT_URI)
    # redirects to google auth page
    return HttpResponseRedirect(oauth_url)

def GoogleCalendarRedirectView(request):
    try:
        credentials = google_apis_oauth.get_crendentials_from_callback(
            request,
            JSON_FILEPATH,
            SCOPES,
            REDIRECT_URI
        )

        # Stringify credentials
        stringified_token = google_apis_oauth.stringify_credentials(
            credentials)

    except InvalidLoginException:
        #if credentials are invalid
        return HttpResponse("invalid")

    creds, refreshed = google_apis_oauth.load_credentials(stringified_token)

    # Using credentials to access Events
    service = build('calendar', 'v3', credentials=creds)
    events_result = service.events().list(
        calendarId='primary', singleEvents=True,
        orderBy='startTime').execute()
    events = events_result.get('items', [])

    # if no events are found
    if not events:
        return HttpResponse("NO EVENTS FOUND")
    for event in events:
        start = event['start'].get('dateTime', event['start'].get('date'))
    return render(request,"events.html",{'events':events})