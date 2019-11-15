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

#include "scampreadme.h"
#include "ui_scampreadme.h"

ScampReadme::ScampReadme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScampReadme)
{
    ui->setupUi(this);
}

ScampReadme::~ScampReadme()
{
    delete ui;
}
