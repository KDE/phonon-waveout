/*  This file is part of the KDE project
    Copyright (C) 2006 Matthias Kretz <kretz@kde.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License version 2 as published by the Free Software Foundation.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.

*/

#ifndef PHONON_UI_EFFECTWIDGET_P_H
#define PHONON_UI_EFFECTWIDGET_P_H

#include "effectwidget.h"
#include "../effectparameter.h"
#include <QHash>

namespace Phonon
{
namespace Ui
{
	class EffectWidgetPrivate
	{
		Q_DECLARE_PUBLIC( EffectWidget )
		protected:
			EffectWidget* q_ptr;

		private:
			Effect* effect;
			QHash<QObject*, Phonon::EffectParameter> parameterForObject;
	};
}} // namespace Phonon::Ui
#endif // PHONON_UI_EFFECTWIDGET_P_H

// vim: sw=4 ts=4 tw=80
