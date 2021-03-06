/*
 * Copyright 2013-2014 Christian Loose <christian.loose@hamburg.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QDialog>

namespace Ui {
class OptionsDialog;
}
class Options;
class SnippetCollection;


class OptionsDialog : public QDialog
{
    Q_OBJECT
    
public:
    OptionsDialog(Options *opt, SnippetCollection *collection, const QList<QAction*> &acts, QWidget *parent = 0);
    ~OptionsDialog();

protected:
    void done(int result);

private slots:
    void manualProxyRadioButtonToggled(bool checked);
    void currentSnippetChanged(const QModelIndex &current, const QModelIndex &previous);
    void snippetTextChanged();
    void addSnippetButtonClicked();
    void removeSnippetButtonClicked();
    void validateShortcut(int row, int column);

private:
    void setupShortcutsTable();
    void readState();
    void saveState();

private:
    Ui::OptionsDialog *_ui;
    Options *_options;
    SnippetCollection *_snippet_collection;
    QList<QAction*> _actions;
};

#endif // OPTIONSDIALOG_H
