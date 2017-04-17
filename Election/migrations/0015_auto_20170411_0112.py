# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('Election', '0014_auto_20170411_0111'),
    ]

    operations = [
        migrations.RenameField(
            model_name='citizens',
            old_name='user_id',
            new_name='user_name',
        ),
    ]
