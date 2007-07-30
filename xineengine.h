/*  This file is part of the KDE project
    Copyright (C) 2006 Tim Beaulen <tbscope@gmail.com>
    Copyright (C) 2006-2007 Matthias Kretz <kretz@kde.org>

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

#ifndef XINEENGINE_H
#define XINEENGINE_H

#include <QtCore/QSet>
#include <QtCore/QSize>
#include <QtCore/QString>
#include <QtCore/QStringList>

#include <Phonon/Global>

#include <KDebug>
#include <KSharedConfig>

#include <xine.h>

namespace Phonon
{
    class AudioDevice;

namespace Xine
{
    class Backend;
    class XineEnginePrivate;

    class XineEngine
	{
        friend class Phonon::Xine::Backend;
        friend class XineEnginePrivate;
		public:
			static XineEngine* self();
			static xine_t* xine();
			static void xineEventListener( void*, const xine_event_t* );

            static QSet<int> audioOutputIndexes();
            static QString audioOutputName(int audioDevice);
            static QString audioOutputDescription(int audioDevice);
            static QString audioOutputIcon(int audioDevice);
            static bool audioOutputAvailable(int audioDevice);
            static QString audioDriverFor(int audioDevice);
            static QStringList alsaDevicesFor(int audioDevice);
            static xine_audio_port_t *nullPort();
            static xine_video_port_t *nullVideoPort();

            static const QObject *sender();

            static void addCleanupObject(QObject *o) { self()->m_cleanupObjects << o; }
            static void removeCleanupObject(QObject *o) { self()->m_cleanupObjects.removeAll(o); }

        protected:
            XineEngine(const KSharedConfigPtr &cfg);
            ~XineEngine();

		private:
            void checkAudioOutputs();
            void addAudioOutput(AudioDevice dev, QString driver);
            void addAudioOutput(int idx, const QString &n, const QString &desc, const QString &ic,
                    const QString &dr, const QStringList &dev);
			xine_t* m_xine;

            struct AudioOutputInfo
            {
                AudioOutputInfo(int idx, const QString &n, const QString &desc, const QString &ic, const QString &dr, const QStringList &dev)
                    : available(false), index(idx), name(n), description(desc), icon(ic), driver(dr), devices(dev)
                {}
                bool available;
                int index;
                QString name;
                QString description;
                QString icon;
                QString driver;
                QStringList devices;
                bool operator==(const AudioOutputInfo& rhs) { return name == rhs.name && driver == rhs.driver; }
            };
            QList<AudioOutputInfo> m_audioOutputInfos;
            QList<QObject *> m_cleanupObjects;
            KSharedConfigPtr m_config;
            bool m_useOss;
            const XineEnginePrivate *const d;
            xine_audio_port_t *m_nullPort;
            xine_video_port_t *m_nullVideoPort;
	};
}
}

/**
 * Implements needed operator to use Phonon::State with kDebug
 */
inline kdbgstream &operator<<(kdbgstream &stream, const Phonon::State state)
{
    switch(state)
    {
    case Phonon::ErrorState:
        stream << "ErrorState";
        break;
    case Phonon::LoadingState:
        stream << "LoadingState";
        break;
    case Phonon::StoppedState:
        stream << "StoppedState";
        break;
    case Phonon::PlayingState:
        stream << "PlayingState";
        break;
    case Phonon::BufferingState:
        stream << "BufferingState";
        break;
    case Phonon::PausedState:
        stream << "PausedState";
        break;
    }
    return stream;
}

#endif // XINEENGINE_H
// vim: sw=4 ts=4 tw=80 et
