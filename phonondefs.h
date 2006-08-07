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

#ifndef PHONONDEFS_H
#define PHONONDEFS_H

#define K_DECLARE_PRIVATE( classname ) \
	inline classname ## Private* k_func() { return reinterpret_cast<classname ## Private*>( k_ptr ); } \
	inline const classname ## Private* k_func() const { return reinterpret_cast<classname ## Private*>( k_ptr ); } \
	friend class classname ## Private;

/**
 * \internal
 * Used in class declarations to provide the needed functions. This is used for
 * abstract base classes.
 *
 * \param classname The Name of the class this macro is used for.
 *
 * Example:
 * \code
 * class AbstractEffect : public QObject
 * {
 *   Q _OBJECT
 *   Q_PROPERTY( int propertyA READ propertyA WRITE setPropertyA )
 *   PHONON_ABSTRACTBASE( AbstractEffect )
 *   public:
 *     int propertyA() const;
 *     void setPropertyA( int );
 * };
 * \endcode
 *
 * \see PHONON_OBJECT
 * \see PHONON_HEIR
 */
#define PHONON_ABSTRACTBASE( classname ) \
protected: \
	/**
	 * \internal
	 * Constructor that is called from derived classes.
	 *
	 * \param parent Standard QObject parent.
	 */ \
	classname( classname ## Private& dd, QObject* parent ); \
	/**
	 * \internal
	 * After construction of the Iface object this method is called
	 * throughout the complete class hierarchy in order to set up the
	 * properties that were already set on the public interface.
	 *
	 * An example implementation could look like this:
	 * \code
	 * ParentClass::setupIface();
	 * m_iface->setPropertyA( d->propertyA );
	 * m_iface->setPropertyB( d->propertyB );
	 * \endcode
	 */ \
	void setupIface();

/**
 * \internal
 * Used in class declarations to provide the needed functions. This is used for
 * classes that inherit QObject directly.
 *
 * \param classname The Name of the class this macro is used for.
 *
 * Example:
 * \code
 * class EffectSettings : public QObject
 * {
 *   Q _OBJECT
 *   Q_PROPERTY( int propertyA READ propertyA WRITE setPropertyA )
 *   PHONON_OBJECT( EffectSettings )
 *   public:
 *     int propertyA() const;
 *     void setPropertyA( int );
 * };
 * \endcode
 *
 * \see PHONON_ABSTRACTBASE
 * \see PHONON_HEIR
 */
#define PHONON_OBJECT( classname ) \
public: \
	/**
	 * Standard QObject constructor.
	 *
	 * \param parent QObject parent
	 */ \
	classname( QObject* parent = 0 ); \
protected: \
	/**
	 * \internal
	 * After construction of the Iface object this method is called
	 * throughout the complete class hierarchy in order to set up the
	 * properties that were already set on the public interface.
	 *
	 * An example implementation could look like this:
	 * \code
	 * ParentClass::setupIface();
	 * m_iface->setPropertyA( d->propertyA );
	 * m_iface->setPropertyB( d->propertyB );
	 * \endcode
	 */ \
	void setupIface();

/**
 * \internal
 * Used in class declarations to provide the needed functions. This is used for
 * classes that inherit another Phonon object.
 *
 * \param classname The Name of the class this macro is used for.
 *
 * Example:
 * \code
 * class ConcreteEffect : public AbstractEffect
 * {
 *   Q _OBJECT
 *   Q_PROPERTY( int propertyB READ propertyB WRITE setPropertyB )
 *   PHONON_HEIR( ConcreteEffect )
 *   public:
 *     int propertyB() const;
 *     void setPropertyB( int );
 * };
 * \endcode
 *
 * \see PHONON_ABSTRACTBASE
 * \see PHONON_OBJECT
 */
#define PHONON_HEIR( classname ) \
public: \
	/**
	 * Standard QObject constructor.
	 *
	 * \param parent QObject parent
	 */ \
	classname( QObject* parent = 0 ); \
protected: \
	/**
	 * \internal
	 * After construction of the Iface object this method is called
	 * throughout the complete class hierarchy in order to set up the
	 * properties that were already set on the frontend objects.
	 *
	 * In the implementation don't forget to call the parent implementation
	 * of this method.
	 */ \
	void setupIface();

#endif // PHONONDEFS_H
