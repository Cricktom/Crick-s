# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('Election', '0013_auto_20170411_0107'),
    ]

    operations = [
        migrations.CreateModel(
            name='Citizens',
            fields=[
                ('user_id', models.IntegerField(serialize=False, primary_key=True)),
                ('First_name', models.TextField()),
                ('Last_name', models.TextField()),
                ('Address', models.TextField()),
                ('email', models.EmailField(max_length=200)),
                ('contact', models.TextField()),
            ],
        ),
        migrations.AlterField(
            model_name='candidates',
            name='user_name',
            field=models.ForeignKey(to='Election.Citizens'),
        ),
        migrations.AlterField(
            model_name='login_data',
            name='email',
            field=models.EmailField(max_length=254, verbose_name=b'Citizens'),
        ),
        migrations.AlterField(
            model_name='login_data',
            name='user_name',
            field=models.ForeignKey(to='Election.Citizens'),
        ),
        migrations.AlterField(
            model_name='vote_casted',
            name='user_name',
            field=models.ForeignKey(to='Election.Citizens'),
        ),
        migrations.DeleteModel(
            name='Voters',
        ),
    ]
