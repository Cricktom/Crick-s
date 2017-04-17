# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('Election', '0015_auto_20170411_0112'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='vote_casted',
            name='casted',
        ),
    ]
