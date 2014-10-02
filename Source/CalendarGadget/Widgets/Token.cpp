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

#include "StdAfx.h"
#include "Token.h"

/*!
Create a new instance of the Token class.
*/
Token::Token(QWidget *parent) : QLabel(parent)
{
  date = QDate();

  setAttribute(Qt::WA_Hover, true);
  resize(200,200);

  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

/*!
Clean up.
*/
Token::~Token()
{

}

/*!
This function sets the date for the token.
*/
void Token::setDate(const QDate& newDate, const int& currentMonth)
{
  date = newDate;
  month = currentMonth; 
  setDisplayText(false);
  setToolTip("");
}

/*!
This function sets the events for the token. All events are passed and the token 
selects the relevant ones.
*/
void Token::setEvents(EventList events)
{
  bool hasEvents = false;
  QString tooltip;

  foreach (Event event, events)
  {
    if (date == event.getDate())
    {
      if (tooltip.isEmpty())
      {
        tooltip = QString("<font size=\"3\" color=\"black\" face=\"Verdana\"><b>Events:</b></font>"
          "<ul><li><font size=\"3\" color=\"black\" face=\"Verdana\">%1</font></color></li>").
          arg(event.getTitle());

        hasEvents = true;
      }
      else
      {
        tooltip = tooltip + QString("<li><font size=\"3\" color=\"black\" face=\"Verdana\">%1</font></color></li>").
          arg(event.getTitle());
      }
    }
  }

  if (hasEvents)
  {
    setToolTip(tooltip + "</ul>");
  }
  else
  {
    setToolTip("");
  }

  if (hasEvents)
    setDisplayText(true);
}

void Token::setDisplayText(bool hasEvents)
{
  QString dayText;

  if (hasEvents)
  {
    if (date.month() == month)
    {
      if (date == QDate::currentDate())
      {
        dayText = QString("<b><font size=\"4\" color=\"maroon\" face=\"Verdana\">%1</font></color></b>").
          arg(date.day());
      }
      else
      {
        dayText = QString("<b><font size=\"4\" color=\"maroon\" face=\"Verdana\">%1</font></color></b>").
          arg(date.day());
      }
    }
    else
    {
      dayText = QString("<font size=\"4\" color=\"maroon\" face=\"Verdana\">%1</font></color>").
        arg(date.day());
    }
  }
  else
  {
    if (date.month() == month)
    {
      if (date == QDate::currentDate())
      {
        dayText = QString("<b><font size=\"4\" color=\"black\" face=\"Verdana\">%1</font></color></b>").
          arg(date.day());
      }
      else
      {
        dayText = QString("<font size=\"4\" color=\"black\" face=\"Verdana\">%1</font></color>").
          arg(date.day());
      }
    }
    else
    {
      dayText = QString("<font size=\"4\" color=\"gray\" face=\"Verdana\">%1</font></color>").
        arg(date.day());
    }
  }

  setText(dayText);
}

/*!
Override the mouse move event. Call the default widget implementation in order 
to pass this message to the parent also.
*/
void Token::mouseMoveEvent(QMouseEvent * event)
{
  QLabel::mouseMoveEvent(event);
  QWidget::mouseMoveEvent(event);
}

/*!
Override the mouse press event. Call the default widget implementation in order 
to pass this message to the parent also.
*/
void Token::mousePressEvent(QMouseEvent * event)
{
  QLabel::mousePressEvent(event);
  QWidget::mousePressEvent(event);
}

/*!
Override the mouse release event. Call the default widget implementation in order 
to pass this message to the parent also.
*/
void Token::mouseReleaseEvent(QMouseEvent * event)
{
  QLabel::mouseReleaseEvent(event);
  QWidget::mouseReleaseEvent(event);
}

/*!
Override the paint event. If the token displays a date and this is the current
date this functions also draws the background.
*/
void Token::paintEvent(QPaintEvent *event)
{
  if (date.isValid())
  {
    if (date == QDate::currentDate())
    {
      QPainter painter(this);
      QLinearGradient linearGradient;
      QRect drawRect;
      QPen pen;

      linearGradient = QLinearGradient(0, 0, 0, rect().height() + 1);
      linearGradient.setColorAt(0.0, QColor::fromRgb(255, 255, 180, 255));
      linearGradient.setColorAt(1.0, Qt::gray);

      pen = QPen(Qt::gray, 1);

      painter.setRenderHint(QPainter::Antialiasing, false);
      painter.setBrush(linearGradient);
      painter.setPen(pen);
      drawRect = QRect(rect().x(), rect().y(), rect().width()-1, rect().height()-1);
      painter.drawRoundedRect(drawRect, 2, 2, Qt::AbsoluteSize);
    }
  }

  QLabel::paintEvent(event);
}
