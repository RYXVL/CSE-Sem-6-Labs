from django.urls import path
from . import views

urlpatterns = [
    path('index/', views.index, name = 'index'),
    path('book/', views.book, name = 'book'),
    path('issue/', views.issue, name = 'issue'),
    path('display/', views.display, name = 'display'),
    path('filter/', views.filter, name = 'filter')
]