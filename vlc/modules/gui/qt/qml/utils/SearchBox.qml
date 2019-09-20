/*****************************************************************************
 * Copyright (C) 2019 VLC authors and VideoLAN
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * ( at your option ) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/
import QtQuick 2.11
import QtQuick.Controls 2.4

import "qrc:///style/"
import "qrc:///utils/" as Utils

Utils.NavigableFocusScope {

    id: root

    width: content.width
    height: content.height

    property variant contentModel

    property bool expanded: false

    onExpandedChanged: {
        if (expanded) {
            searchBox.forceActiveFocus()
            icon.KeyNavigation.right = searchBox
            animateExpand.start()
        }
        else {
            searchBox.placeholderText = ""
            searchBox.text = ""
            icon.forceActiveFocus()
            icon.KeyNavigation.right = null
            animateRetract.start()
        }
    }

    onActiveFocusChanged: {
        if (!activeFocus && searchBox.text == "")
            expanded = false
    }

    PropertyAnimation {
        id: animateExpand;
        target: searchBox;
        properties: "width"
        duration: 200
        to: VLCStyle.widthSearchInput
        onStopped: {
            searchBox.placeholderText = qsTr("filter")
        }
    }

    PropertyAnimation {
        id: animateRetract;
        target: searchBox;
        properties: "width"
        duration: 200
        to: 0
    }

    MouseArea {
        id: mouseArea
        hoverEnabled: true
        anchors.fill: parent

        onClicked: {
            searchBox.forceActiveFocus()
        }

        onEntered: {
            expanded = true
        }

        onExited: {
            if (searchBox.text == "")
                expanded = false
        }


        Row {
            id: content

            Utils.IconToolButton {
                id: icon

                size: VLCStyle.icon_normal
                text: VLCIcons.topbar_filter

                focus: true

                onClicked: {
                    if (searchBox.text == "")
                        expanded = !expanded
                }
            }

            TextField {
                id: searchBox

                anchors.verticalCenter: parent.verticalCenter

                font.pixelSize: VLCStyle.fontSize_normal

                color: VLCStyle.colors.buttonText
                width: 0

                selectByMouse: true

                background: Rectangle {
                    color: VLCStyle.colors.button
                    border.color: {
                        if ( searchBox.text.length < 3 && searchBox.text.length !== 0 )
                            return VLCStyle.colors.alert
                        else if ( searchBox.activeFocus )
                            return VLCStyle.colors.accent
                        else
                            return VLCStyle.colors.buttonBorder
                    }
                }

                onTextChanged: {
                    if (contentModel !== undefined)
                        contentModel.searchPattern = text;
                }
            }
        }
    }
}
