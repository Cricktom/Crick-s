# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('Election', '0003_voters'),
    ]

    operations = [
        migrations.AlterField(
            model_name='voters',
            name='user_id',
            field=models.TextField(serialize=False, primary_key=True),
        ),
    ]
