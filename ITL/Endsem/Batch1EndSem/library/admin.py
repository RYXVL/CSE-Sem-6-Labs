from django.contrib import admin
from .models import BookModel, IssuerModel

class BookModelAdmin(admin.ModelAdmin):
    list_display = ['bookname', 'authorname', 'publishername']

class IssuerModelAdmin(admin.ModelAdmin):
    list_display = ['issuername', 'bookname', 'issuedate']

admin.site.register(BookModel, BookModelAdmin)
admin.site.register(IssuerModel, IssuerModelAdmin)