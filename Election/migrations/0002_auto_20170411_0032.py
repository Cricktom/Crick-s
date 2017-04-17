# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('Election', '0001_initial'),
    ]

    operations = [
        migrations.AlterField(
            model_name='voter',
            name='user_id',
            field=models.TextField(max_length=300, serialize=False, primary_key=True),
        ),
    ]
