# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('Election', '0017_auto_20170414_1323'),
    ]

    operations = [
        migrations.CreateModel(
            name='Election_duration',
            fields=[
                ('election_year', models.IntegerField(serialize=False, primary_key=True)),
                ('polling_date', models.DateField()),
                ('candidature_date', models.DateField()),
            ],
        ),
        migrations.DeleteModel(
            name='Election_period',
        ),
    ]
