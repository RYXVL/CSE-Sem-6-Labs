from django.contrib import admin
from .models import StudentModel

class StudentModelAdmin(admin.ModelAdmin):
    list_display = ['name', 'regno']

admin.site.register(StudentModel, StudentModelAdmin)