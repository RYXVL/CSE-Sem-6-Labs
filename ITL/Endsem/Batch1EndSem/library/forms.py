from django import forms
from .models import BookModel, IssuerModel

class BookModelForm(forms.ModelForm):
    class Meta:
        model = BookModel
        exclude = ()


class IssuerModelForm(forms.ModelForm):
    class Meta:
        model = IssuerModel
        exclude = ()

class FilterForm(forms.Form):
    issuername = forms.CharField(max_length=100, label='Issuer Name: ')