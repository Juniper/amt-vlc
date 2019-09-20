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
import QtQml.Models 2.2
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0

import "qrc:///utils/" as Utils
import "qrc:///style/"

NavigableFocusScope {
    id: root

    //forwarded from subview
    signal actionForSelection( var selection )
    signal contextMenuButtonClicked(Item menuParent, var menuModel)
    signal rightClick(Item menuParent, var menuModel)

    property var sortModel: ListModel { }
    property Component colDelegate: Item { }
    property var model: []

    property alias contentHeight: view.contentHeight

    property alias interactive: view.interactive

    property alias section: view.section

    property alias currentIndex: view.currentIndex
    property alias currentItem: view.currentItem

    property alias headerItem: view.headerItem
    property color headerColor

    property alias delegateModel: delegateModel
    property real rowHeight: VLCStyle.fontHeight_normal + VLCStyle.margin_large
    property alias spacing: view.spacing

    Utils.SelectableDelegateModel {
        id: delegateModel

        model: root.model

        delegate: Package {
            id: element
            property var rowModel: model

            Rectangle {
                Package.name: "list"
                id: lineView

                width: root.width
                height: root.rowHeight
                color: VLCStyle.colors.bg

                MouseArea {
                    id: hoverArea
                    anchors.fill: parent
                    hoverEnabled: true
                    Keys.onMenuPressed: root.contextMenuButtonClicked(contextButton,rowModel)
                    acceptedButtons: Qt.RightButton | Qt.LeftButton

                    onClicked: {
                        delegateModel.updateSelection( mouse.modifiers , view.currentIndex, index)
                        view.currentIndex = rowModel.index
                        lineView.forceActiveFocus()

                        if (mouse.button === Qt.RightButton){
                            root.rightClick(lineView,rowModel)
                        }
                    }

                    onDoubleClicked: {
                        actionForSelection(delegateModel.selectedGroup)
                    }
                    RectangularGlow {
                        visible: element.DelegateModel.inSelected || hoverArea.containsMouse
                        anchors.fill: parent
                        glowRadius: VLCStyle.margin_xxsmall
                        color: VLCStyle.colors.getBgColor(element.DelegateModel.inSelected, hoverArea.containsMouse, lineView.activeFocus)
                    }

                    Rectangle{
                        anchors.fill: parent
                        anchors.topMargin: VLCStyle.margin_xxsmall
                        anchors.bottomMargin: VLCStyle.margin_xxsmall
                        anchors.leftMargin: VLCStyle.margin_xxxsmall
                        anchors.rightMargin: VLCStyle.margin_xxxsmall
                        color: VLCStyle.colors.bg
                        radius: height / 10

                        Row {
                            anchors {
                                fill: parent
                            }
                            Repeater {
                                model: sortModel

                                Item {
                                    height: parent.height
                                    width: model.width * view.width
                                    Layout.alignment: Qt.AlignVCenter
                                    Loader{
                                        anchors.fill: parent
                                        sourceComponent: colDelegate

                                        property var rowModel: element.rowModel
                                        property var colModel: model

                                    }

                                }
                            }
                        }
                    }
                }
            }
        }
    }


    KeyNavigableListView {
        id: view

        anchors.fill: parent

        focus: true

        model : delegateModel.parts.list
        modelCount: delegateModel.items.count

        headerPositioning: ListView.OverlayHeader

        header: Rectangle {
            width: parent.width
            height: childrenRect.height
            color: headerColor
            visible: view.modelCount > 0
            z: 3

            Column {
                width: parent.width
                height: childrenRect.height

                Row {
                    x: VLCStyle.margin_normal
                    width: childrenRect.width - 2 * VLCStyle.margin_normal
                    height: childrenRect.height + VLCStyle.margin_xxsmall

                    Repeater {
                        model: sortModel
                        MouseArea {
                            height: VLCStyle.fontHeight_normal
                            width: model.width * view.width
                            //Layout.alignment: Qt.AlignVCenter

                            Text {
                                text: model.text || ""
                                elide: Text.ElideRight
                                font {
                                    pixelSize: VLCStyle.fontSize_normal

                                }
                                color: VLCStyle.colors.buttonText
                                horizontalAlignment: Text.AlignLeft
                                anchors {
                                    fill: parent
                                    leftMargin: VLCStyle.margin_xsmall
                                    rightMargin: VLCStyle.margin_xsmall
                                }
                            }

                            Text {
                                text: (root.model.sortOrder === Qt.AscendingOrder) ? "▼" : "▲"
                                visible: root.model.sortCriteria === model.criteria
                                font.pixelSize: VLCStyle.fontSize_normal
                                color: VLCStyle.colors.accent
                                anchors {
                                    right: parent.right
                                    leftMargin: VLCStyle.margin_xsmall
                                    rightMargin: VLCStyle.margin_xsmall
                                }
                            }
                            onClicked: {
                                if (root.model.sortCriteria !== model.criteria)
                                    root.model.sortCriteria = model.criteria
                                else
                                    root.model.sortOrder = (root.model.sortOrder === Qt.AscendingOrder) ? Qt.DescendingOrder : Qt.AscendingOrder
                            }
                        }
                    }
                }

                Rectangle {
                    width: parent.width
                    height: 1
                    color: VLCStyle.colors.textInactive
                }
            }
        }

        onSelectAll: delegateModel.selectAll()
        onSelectionUpdated: delegateModel.updateSelection( keyModifiers, oldIndex, newIndex )
        onActionAtIndex: root.actionForSelection( delegateModel.selectedGroup )

        navigationParent: root
    }

    /*
     *define the intial position/selection
     * This is done on activeFocus rather than Component.onCompleted because delegateModel.
     * selectedGroup update itself after this event
     */
    onActiveFocusChanged: {
        if (activeFocus && delegateModel.items.count > 0 && delegateModel.selectedGroup.count === 0) {
            var initialIndex = 0
            if (view.currentIndex !== -1)
                initialIndex = view.currentIndex
            delegateModel.items.get(initialIndex).inSelected = true
            view.currentIndex = initialIndex
        }
    }

}
