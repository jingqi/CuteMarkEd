/*
 * Copyright 2015 Aetf <7437103@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include <QRegularExpression>
#include "yamlheaderchecker.h"

YamlHeaderChecker::YamlHeaderChecker(const QString &text)
{
    QRegularExpression rx(R"(^---\s*\n(.*?\n)?(---|\.\.\.)\s*(\n|$))",
                          QRegularExpression::DotMatchesEverythingOption);
    QRegularExpressionMatch match = rx.match(text);
    if (match.hasMatch()) {
        m_header = match.captured(0);
        m_body = text.mid(m_header.length());
    } else {
        m_body = text;
    }
}

bool YamlHeaderChecker::hasHeader() const
{
    return !m_header.isEmpty();
}

QString YamlHeaderChecker::header() const
{
    return m_header;
}

QString YamlHeaderChecker::body() const
{
    return m_body;
}

int YamlHeaderChecker::bodyOffset() const
{
    return m_header.length();
}
