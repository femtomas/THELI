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

#ifndef STATUS_H
#define STATUS_H

#include <QString>
#include <QCheckBox>
#include <QToolButton>
#include <QList>
#include <QLineEdit>
#include <QObject>

// This class keeps track of the actual processing status (what has been done to the data)
// and of the predicted processing status (based on what has been done and which check boxes are marked)
// It also contains lists of all relevant widgets (CheckBoxes, configure Buttons, Actions)
// so that common actions can be coded using loops instead of explicitly typing everything out.
class Status : public QObject
{
    Q_OBJECT

public:
    Status();

    void history2checkbox();
//    void history2actions();
    QString getStatusFromHistory(bool keepblanks = false);
    QString predictStatus(QString taskBasename);
    QString checkboxStatus(QCheckBox *cb);
    QString predictStatusAfter(QString taskBasename);

    // These lists contain the tasks, in the order in which they occur in the GUI
    QList<bool> listHistory;                // Whether a task has been executed or not; this is the central piece that rules it all
    QList<QCheckBox*> listCheckBox;         // the list of all task checkboxes
    QList<QToolButton*> listToolButtons;    // the list of all tool buttons
  //  QList<QAction*> listStatusActions;      // the list of all status actions
    QList<QString> listName;                // The unique ID string common to checkbox, undo Button and Action
    QList<QLineEdit*> listDataDirs;         // The list of all data dir LineEdits
    QList<QString> listCurrentValue;        // The current string value (A,B,C,M,D or empty) associated with the checkbox
    QList<QString> listFixedValue;          // (constant). A character for each task box, used to comprise the processing string
    QList<bool> listBreakpoints;            // (constant). The character associated to each processing task (mostly blanks)
    QMap<QString, int> indexMap;            // Identifies the index of a task (the order in which the task appears)

    // The number of task checkboxes in the GUI; sorry, hardcoded.
    const int numtasks = 19;

    void init();
    void statusstringToHistory(QString &statusstring);
    void clearAllCheckBoxes();

private:
    int lastExecutedTaskId();

signals:
    void statusChanged();

public slots:
    void updateStatus();
    void updateStatusReceived(QString taskBasename, bool success);
};

#endif // STATUS_H
