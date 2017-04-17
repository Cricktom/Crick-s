# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('Election', '0005_auto_20170411_0038'),
    ]

    operations = [
        migrations.AlterField(
            model_name='candidates',
            name='user_id',
            field=models.ForeignKey(to='Election.Voters'),
        ),
        migrations.AlterField(
            model_name='login_data',
            name='email',
            field=models.EmailField(max_length=254, verbose_name=b'Voters'),
        ),
        migrations.AlterField(
            model_name='login_data',
            name='user_id',
            field=models.ForeignKey(to='Election.Voters'),
        ),
        migrations.AlterField(
            model_name='vote_casted',
            name='user_id',
            field=models.ForeignKey(to='Election.Voters'),
        ),
        migrations.AlterField(
            model_name='voters',
            name='user_id',
            field=models.CharField(max_length=30, serialize=False, primary_key=True),
        ),
        migrations.DeleteModel(
            name='Voter',
        ),
    ]
