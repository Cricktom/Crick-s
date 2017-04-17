# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('Election', '0016_remove_vote_casted_casted'),
    ]

    operations = [
        # migrations.RemoveField(
        #     model_name='election_period',
        #     name='id',
        # ),
        migrations.AlterField(
            model_name='election_period',
            name='election_year',
            field=models.IntegerField(serialize=False, primary_key=True),
        ),
    ]
