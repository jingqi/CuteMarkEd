﻿/*
 * Copyright 2014 Christian Loose <christian.loose@hamburg.de>
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
#ifndef HTMLPREVIEWCONTROLLER_H
#define HTMLPREVIEWCONTROLLER_H

#include <QObject>

class QAction;
class QNetworkDiskCache;
class HtmlPreviewer;

class HtmlPreviewController : public QObject
{
    Q_OBJECT
public:
    explicit HtmlPreviewController(HtmlPreviewer *view, QObject *parent = 0);

public slots:
    void zoomInView();
    void zoomOutView();
    void resetZoomOfView();

private:
    void createActions();
    QAction *createAction(const QString &text, const QKeySequence &shortcut);
    void registerActionsWithView();

    void setupNetworkDiskCache();
    
private:
    HtmlPreviewer *_view;
    QAction *_zoom_in_action;
    QAction *_zoom_out_action;
    QAction *_zoom_reset_action;
    QNetworkDiskCache *_disk_cache;
};

#endif // HTMLPREVIEWCONTROLLER_H

