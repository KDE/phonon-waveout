/*  This file is part of the KDE project
    Copyright (C) 2007 Matthias Kretz <kretz@kde.org>

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

#ifndef PHONON_FACTORY_P_H
#define PHONON_FACTORY_P_H

#include "factory.h"
#include <QPointer>
#include <kcomponentdata.h>

namespace Phonon
{
class FactoryPrivate : public Phonon::Factory::Sender
{
    friend QObject *Factory::backend(bool);
    Q_OBJECT
    public:
        FactoryPrivate();
        ~FactoryPrivate();
        void createBackend();

        QPointer<QObject> backend;
        KService::Ptr service;

        QList<QObject*> objects;
        QList<BasePrivate*> basePrivateList;
        KComponentData componentData;

    private Q_SLOTS:
        /**
         * This is called via DBUS when the user changes the Phonon Backend.
         */
        void phononBackendChanged();

        /**
         * unregisters the backend object
         */
        void objectDestroyed(QObject *);

        void objectDescriptionChanged(ObjectDescriptionType);
};
} // namespace Phonon

#endif // PHONON_FACTORY_P_H
// vim: sw=4 sts=4 et tw=100
