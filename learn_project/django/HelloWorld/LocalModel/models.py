from django.db import models
import django.utils.timezone as timezone

# Create your models here.
class Duser(models.Model):
    gender=(
        ('male',"男"),
        ('female',"女"),
    )
    name=models.CharField(max_length=128,unique=True)
    password=models.CharField(max_length=128)
    email=models.EmailField(unique=True)
    sex = models.CharField(max_length=32, choices=gender, default="男")
    c_time = models.DateTimeField(default = timezone.now)
    
    def __str__(self):
        return self.name
    
    class Meta:
        ordering = ["-c_time"]
        verbose_name = "用户"
        verbose_name_plural = "用户"