# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('Election', '0004_auto_20170411_0038'),
    ]

    operations = [
        migrations.AlterField(
            model_name='voters',
            name='user_id',
            field=models.TextField(max_length=200, serialize=False, primary_key=True),
        ),
    ]
