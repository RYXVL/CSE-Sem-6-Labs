from django.shortcuts import render
from .models import BookModel, IssuerModel
from .forms import BookModelForm, IssuerModelForm, FilterForm
from django.http import HttpResponse

def index(request):
    return render(request, 'index.html')

def book(request):
    bookform = BookModelForm()
    if request.method == 'POST':
        bookform = BookModelForm(request.POST)
        if bookform.is_valid():
            bookform.save()
    return render(request, 'book.html', {'form': BookModelForm()})


def issue(request):
    issuerform = IssuerModelForm()
    filterform = FilterForm()
    if request.method == 'POST':
        issuerform = IssuerModelForm(request.POST)
        if issuerform.is_valid():
            issuerform.save()
    return render(request, 'issue.html', {'form': IssuerModelForm(), 'filterform': filterform})

def display(request):
    bookdata = BookModel.objects.all()
    issuerdata = IssuerModel.objects.all()
    return render(request, 'display.html', {'bookdata': bookdata, 'issuerdata': issuerdata})

def filter(request):
    issuername = ''
    if request.method == 'POST':
        filterform = FilterForm(request.POST)
        if filterform.is_valid():
            issuername = filterform.cleaned_data['issuername']
            data = IssuerModel.objects.filter(issuername__icontains = issuername)
        return render(request, 'filter.html', {'heading': issuername, 'data': data})
