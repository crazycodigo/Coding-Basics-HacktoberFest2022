from django.urls import path
from . import views


urlpatterns = [
    path('', views.home),
    path('rest/v1/calender/init/', views.GoogleCalendarInitVIew),
    path('rest/v1/calendar/redirect/', views.GoogleCalendarRedirectView)

]
