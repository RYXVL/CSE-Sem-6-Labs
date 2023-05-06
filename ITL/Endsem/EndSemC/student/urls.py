from django.urls import path
from . import views

urlpatterns = [
    path('index/', views.index, name = 'index'),
    path('display/', views.display, name = 'display'),
    path('filter/', views.filter, name = 'filter')
]
