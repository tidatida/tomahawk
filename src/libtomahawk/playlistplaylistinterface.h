/* === This file is part of Tomahawk Player - <http://tomahawk-player.org> ===
 *
 *   Copyright 2010-2011, Christian Muehlhaeuser <muesli@tomahawk-player.org>
 *
 *   Tomahawk is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Tomahawk is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Tomahawk. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PLAYLISTPLAYLISTINTERFACE_H
#define PLAYLISTPLAYLISTINTERFACE_H

#include <QObject>
#include <QList>
#include <QSharedPointer>

#include "typedefs.h"
#include "result.h"
#include "playlistinterface.h"
#include "query.h"

#include "dllmacro.h"

namespace Tomahawk
{

class DLLEXPORT PlaylistPlaylistInterface : public Tomahawk::PlaylistInterface
{
Q_OBJECT

public:
    PlaylistPlaylistInterface( Tomahawk::Playlist* playlist );
    virtual ~PlaylistPlaylistInterface();

    virtual QList<Tomahawk::query_ptr> tracks();

    virtual int unfilteredTrackCount() const;
    virtual int trackCount() const;

    virtual bool hasNextItem() { return false; }
    virtual Tomahawk::result_ptr currentItem() const { return m_currentItem; }

    virtual Tomahawk::result_ptr siblingItem( int /*itemsAway*/ ) { return result_ptr(); }

    virtual PlaylistInterface::RepeatMode repeatMode() const { return PlaylistInterface::NoRepeat; }
    virtual bool shuffled() const { return false; }

    virtual void setFilter( const QString& /*pattern*/ ) {}

signals:
    void repeatModeChanged( PlaylistInterface::RepeatMode mode );
    void shuffleModeChanged( bool enabled );

    void trackCountChanged( unsigned int tracks );
    void sourceTrackCountChanged( unsigned int tracks );

    void nextTrackReady();

public slots:
    virtual void setRepeatMode( PlaylistInterface::RepeatMode ) {}
    virtual void setShuffled( bool ) {}

private:
    PlaylistPlaylistInterface();
    Q_DISABLE_COPY( PlaylistPlaylistInterface )

    QWeakPointer< Tomahawk::Playlist > m_playlist;

    result_ptr m_currentItem;
};

}

#endif // PLAYLISTPLAYLISTINTERFACE_H
