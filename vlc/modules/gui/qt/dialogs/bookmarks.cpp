/*****************************************************************************
 * bookmarks.cpp : Bookmarks
 ****************************************************************************
 * Copyright (C) 2007-2008 the VideoLAN team
 *
 * Authors: Antoine Lejeune <phytos@via.ecp.fr>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "dialogs/bookmarks.hpp"
#include "components/player_controller.hpp"

#include <QHBoxLayout>
#include <QSpacerItem>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QModelIndexList>

BookmarksDialog::BookmarksDialog( intf_thread_t *_p_intf ):QVLCFrame( _p_intf )
{
    b_ignore_updates = false;
    setWindowFlags( Qt::Tool );
    setWindowOpacity( var_InheritFloat( p_intf, "qt-opacity" ) );
    setWindowTitle( qtr( "Edit Bookmarks" ) );
    setWindowRole( "vlc-bookmarks" );

    QHBoxLayout *layout = new QHBoxLayout( this );

    QDialogButtonBox *buttonsBox = new QDialogButtonBox( Qt::Vertical );
    QPushButton *addButton = new QPushButton( qtr( "Create" ) );
    addButton->setToolTip( qtr( "Create a new bookmark" ) );
    buttonsBox->addButton( addButton, QDialogButtonBox::ActionRole );
    delButton = new QPushButton( qtr( "Delete" ) );
    delButton->setToolTip( qtr( "Delete the selected item" ) );
    buttonsBox->addButton( delButton, QDialogButtonBox::ActionRole );
    clearButton = new QPushButton( qtr( "Clear" ) );
    clearButton->setToolTip( qtr( "Delete all the bookmarks" ) );
    buttonsBox->addButton( clearButton, QDialogButtonBox::ResetRole );
#if 0
    QPushButton *extractButton = new QPushButton( qtr( "Extract" ) );
    extractButton->setToolTip( qtr() );
    buttonsBox->addButton( extractButton, QDialogButtonBox::ActionRole );
#endif
    /* ?? Feels strange as Qt guidelines will put reject on top */
    buttonsBox->addButton( new QPushButton( qtr( "&Close" ) ),
                          QDialogButtonBox::RejectRole);

    bookmarksList = new QTreeWidget( this );
    bookmarksList->setRootIsDecorated( false );
    bookmarksList->setAlternatingRowColors( true );
    bookmarksList->setSelectionMode( QAbstractItemView::ExtendedSelection );
    bookmarksList->setSelectionBehavior( QAbstractItemView::SelectRows );
    bookmarksList->setEditTriggers( QAbstractItemView::SelectedClicked );
    bookmarksList->setColumnCount( 3 );
    bookmarksList->resize( sizeHint() );

    QStringList headerLabels;
    headerLabels << qtr( "Description" );
    headerLabels << qtr( "Bytes" );
    headerLabels << qtr( "Time" );
    bookmarksList->setHeaderLabels( headerLabels );

    layout->addWidget( buttonsBox );
    layout->addWidget( bookmarksList );

    CONNECT( THEMIM, bookmarksChanged(),
             this, update() );

    CONNECT( bookmarksList, activated( QModelIndex ), this,
             activateItem( QModelIndex ) );
    CONNECT( bookmarksList, itemChanged( QTreeWidgetItem*, int ),
             this, edit( QTreeWidgetItem*, int ) );
    CONNECT( bookmarksList->model(), rowsInserted( const QModelIndex &, int, int ),
             this, updateButtons() );
    CONNECT( bookmarksList->model(), rowsRemoved( const QModelIndex &, int, int ),
             this, updateButtons() );
    CONNECT( bookmarksList->selectionModel(), selectionChanged( const QItemSelection &, const QItemSelection & ),
             this, updateButtons() );
    BUTTONACT( addButton, add() );
    BUTTONACT( delButton, del() );
    BUTTONACT( clearButton, clear() );

#if 0
    BUTTONACT( extractButton, extract() );
#endif
    CONNECT( buttonsBox, rejected(), this, close() );
    updateButtons();

    restoreWidgetPosition( "Bookmarks", QSize( 435, 280 ) );
    updateGeometry();
}

BookmarksDialog::~BookmarksDialog()
{
    saveWidgetPosition( "Bookmarks" );
}

void BookmarksDialog::updateButtons()
{
    clearButton->setEnabled( bookmarksList->model()->rowCount() > 0 );
    delButton->setEnabled( bookmarksList->selectionModel()->hasSelection() );
}

void BookmarksDialog::update()
{
    //FIXME unimplemented
}

void BookmarksDialog::add()
{
    //FIXME unimplemented
}

void BookmarksDialog::del()
{
    //FIXME unimplemented
}

void BookmarksDialog::clear()
{
    //FIXME unimplemented
}

void BookmarksDialog::edit( QTreeWidgetItem *, int )
{
    //FIXME unimplemented
}

void BookmarksDialog::extract()
{
    // TODO
}

void BookmarksDialog::activateItem( QModelIndex )
{
    //FIXME unimplemented
}

void BookmarksDialog::toggleVisible()
{
    /* Update, to show existing bookmarks in case a new playlist
       was opened */
    if( !isVisible() )
    {
        update();
    }
    QVLCFrame::toggleVisible();
}
