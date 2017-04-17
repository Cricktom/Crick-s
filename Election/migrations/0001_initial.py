# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Candidates',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('vote_count', models.IntegerField(default=0)),
                ('candidature_year', models.DateField()),
                ('agenda', models.TextField(max_length=500, blank=True)),
                ('candidate_designation', models.TextField()),
            ],
        ),
        migrations.CreateModel(
            name='Login_data',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('email', models.EmailField(max_length=254, verbose_name=b'Voter')),
                ('password', models.TextField()),
                ('designation', models.TextField()),
            ],
        ),
        migrations.CreateModel(
            name='Vote_Casted',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('casted', models.IntegerField(default=0)),
                ('casted_year', models.DateField()),
            ],
        ),
        migrations.CreateModel(
            name='Voter',
            fields=[
                ('user_id', models.TextField(max_length=200, serialize=False, primary_key=True)),
                ('First_name', models.TextField()),
                ('Last_name', models.TextField()),
                ('Address', models.TextField()),
                ('email', models.EmailField(max_length=200, primary_key=True)),
                ('contact', models.TextField()),
            ],
        ),
        migrations.AddField(
            model_name='vote_casted',
            name='user_id',
            field=models.ForeignKey(to='Election.Voter'),
        ),
        migrations.AddField(
            model_name='login_data',
            name='user_id',
            field=models.ForeignKey(to='Election.Voter'),
        ),
        migrations.AddField(
            model_name='candidates',
            name='user_id',
            field=models.ForeignKey(to='Election.Voter'),
        ),
    ]
