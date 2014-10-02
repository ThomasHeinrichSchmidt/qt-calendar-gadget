/****************************************************************************
**
** Copyright (C) 2010-2011 B.D. Mihai.
**
** This file is part of CalendarGadget.
**
** CalendarGadget is free software: you can redistribute it and/or modify it 
** under the terms of the GNU Lesser Public License as published by the Free 
** Software Foundation, either version 3 of the License, or (at your option) 
** any later version.
**
** CalendarGadget is distributed in the hope that it will be useful, but 
** WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
** or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser Public License for 
** more details.
**
** You should have received a copy of the GNU Lesser Public License along 
** with CalendarGadget.  If not, see http://www.gnu.org/licenses/.
**
****************************************************************************/

#ifndef TOKEN_H
#define TOKEN_H

#include "../Google/Event.h"

/*!
This class represents a day label. It is derived from QLabel and overrides 
the mouse events in order to be able to drag the calendar.
*/
class Token : public QLabel
{
  Q_OBJECT

  public:
    Token(QWidget *parent = 0);
    virtual ~Token();

    void setDate(const QDate& newDate, const int& currentMonth);
    void setEvents(EventList events);

  protected:
    QDate date;
    int month;
    void setDisplayText(bool hasEvents);

    virtual void paintEvent(QPaintEvent *event);
    virtual void mouseMoveEvent(QMouseEvent * event);
    virtual void mousePressEvent(QMouseEvent * event);
    virtual void mouseReleaseEvent(QMouseEvent * event);
};

#endif

