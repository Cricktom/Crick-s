# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('Election', '0002_auto_20170411_0032'),
    ]

    operations = [
        migrations.CreateModel(
            name='Voters',
            fields=[
                ('user_id', models.TextField(max_length=300, serialize=False, primary_key=True)),
                ('First_name', models.TextField()),
                ('Last_name', models.TextField()),
                ('Address', models.TextField()),
                ('email', models.EmailField(max_length=200, primary_key=True)),
                ('contact', models.TextField()),
            ],
        ),
    ]
