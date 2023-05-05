from django.db import models

class BookModel(models.Model):
    bookname = models.CharField(max_length=100)
    authorname = models.CharField(max_length=100)
    publishername = models.CharField(max_length=100)

    def __str__(self):
        return self.bookname

class IssuerModel(models.Model):
    issuername = models.CharField(max_length=100)
    bookname = models.ForeignKey(BookModel, models.CASCADE)
    issuedate = models.DateField()
