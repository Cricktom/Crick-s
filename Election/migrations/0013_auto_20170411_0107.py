# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('Election', '0012_auto_20170411_0059'),
    ]

    operations = [
        migrations.CreateModel(
            name='Election_period',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('election_year', models.IntegerField()),
                ('polling_date', models.DateField()),
                ('candidature_date', models.DateField()),
            ],
        ),
        migrations.RenameField(
            model_name='candidates',
            old_name='candidature_year',
            new_name='candidature_date',
        ),
    ]
