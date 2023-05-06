from django.db import models

class StudentModel(models.Model):
    name = models.CharField(max_length=100)
    regno = models.PositiveIntegerField()