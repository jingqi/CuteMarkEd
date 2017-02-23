/*
 * Copyright 2015 Christian Loose <christian.loose@hamburg.de>
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

#include "style_manager.h"

#include <QMap>


static const QMap<QString, QString> BUILTIN_MARKDOWN_HIGHLIGHTINGS = {
    { "Default", "default" },
    { "Solarized Light", "solarized-light" },
    { "Solarized Dark", "solarized-dark" },
    { "Clearness Dark", "clearness-dark" },
    { "Byword Dark", "byword-dark" }
};

static const QMap<QString, QString> BUILTIN_CODE_HIGHLIGHTINGS = {
    { "Default", "default" },
    { "Github", "github" },
    { "Solarized Light", "solarized_light" },
    { "Solarized Dark", "solarized_dark" }
};

static const QMap<QString, QString> BUILTIN_PREVIEW_STYLESHEETS = {
    { "Default", "qrc:/css/markdown.css" },
    { "Github", "qrc:/css/github.css" },
    { "Solarized Light", "qrc:/css/solarized-light.css" },
    { "Solarized Dark", "qrc:/css/solarized-dark.css" },
    { "Clearness", "qrc:/css/clearness.css" },
    { "Clearness Dark", "qrc:/css/clearness-dark.css" },
    { "Byword Dark", "qrc:/css/byword-dark.css" }
};

QMap<QString, QString> StyleManager::_custom_preview_stylesheets;


void StyleManager::insertCustomPreviewStylesheet(const QString &styleName, const QString &stylePath)
{
    _custom_preview_stylesheets.insert(styleName, stylePath);
}

QString StyleManager::markdownHighlightingPath(const Theme &theme)
{
    return BUILTIN_MARKDOWN_HIGHLIGHTINGS[theme.markdownHighlighting()];
}

QString StyleManager::codeHighlightingPath(const Theme &theme)
{
    return BUILTIN_CODE_HIGHLIGHTINGS[theme.codeHighlighting()];
}

QString StyleManager::previewStylesheetPath(const Theme &theme)
{
    if (_custom_preview_stylesheets.contains(theme.previewStylesheet())) {
        return _custom_preview_stylesheets[theme.previewStylesheet()];
    }

    return BUILTIN_PREVIEW_STYLESHEETS[theme.previewStylesheet()];
}
