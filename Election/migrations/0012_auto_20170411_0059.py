# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('Election', '0011_auto_20170411_0056'),
    ]

    operations = [
        migrations.RenameField(
            model_name='candidates',
            old_name='user_id',
            new_name='user_name',
        ),
        migrations.RenameField(
            model_name='login_data',
            old_name='user_id',
            new_name='user_name',
        ),
        migrations.RenameField(
            model_name='vote_casted',
            old_name='user_id',
            new_name='user_name',
        ),
        migrations.RemoveField(
            model_name='voters',
            name='user_id',
        ),
        migrations.AddField(
            model_name='voters',
            name='user_name',
            field=models.CharField(default=b'user', max_length=150, serialize=False, primary_key=True),
        ),
    ]
