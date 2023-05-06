from django.shortcuts import render
from .models import StudentModel
from .forms import StudentModelForm
from django.http import HttpResponse

def index(request):
    studentform = StudentModelForm()
    if request.method == 'POST':
        poststudentform = StudentModelForm(request.POST)
        if poststudentform.is_valid():
            poststudentform.save()
            return render(request, 'index.html', {'form': studentform})
        else:
            return HttpResponse('<h1>Error POST form.</h1>')
    else:
        return render(request, 'index.html', {'form': studentform})

def display(request):
    data = StudentModel.objects.all()
    return render(request, 'display.html', {'data': data})

def filter(request):
    if request.method == 'POST':
        regno = request.POST['regno']
        data = StudentModel.objects.filter(regno__icontains = regno)
        return render(request, 'filter.html', {'data': data})
    else:
        return HttpResponse('<h1>Invalid FILTER data.</h1>')