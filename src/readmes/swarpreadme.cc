/*
Copyright (C) 2019 Mischa Schirmer

This file is part of THELI.

THELI is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation, either version 3 of the License, or any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program in the LICENSE file.
If not, see https://www.gnu.org/licenses/ .
*/

#include "swarpreadme.h"
#include "ui_swarpreadme.h"

SwarpReadme::SwarpReadme(long openfiles, long maxopenfiles, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SwarpReadme)
{
    ui->setupUi(this);

    openFiles = openfiles;
    maxOpenFiles = maxopenfiles;

    ui->maxOpenFileLineEdit->setText(QString::number(maxOpenFiles));
    ui->openFileLineEdit->setText(QString::number(openFiles));
}

SwarpReadme::~SwarpReadme()
{
    delete ui;
}
