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

#ifndef SEXWORKER_H
#define SEXWORKER_H

#include "worker.h"

#include <QObject>
#include <QProcess>

class SexWorker : public Worker
{
    Q_OBJECT

public:
    explicit SexWorker(QString command, QString dir, QObject *parent = nullptr);

    QString sexCommand;
    QString sexDirName;
    QProcess *extProcess;

    void abort();  // Currently not used anywhere

public slots:
    void runSex();

private slots:
    void processExternalStdout();
    void processExternalStderr();

signals:
    void errorFound();
    void messageAvailable(QString message, QString type);

};

#endif // SEXWORKER_H
