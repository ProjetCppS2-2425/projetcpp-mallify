import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15      // for WheelHandler
import QtLocation 6.3
import QtPositioning 6.3

Rectangle {
    width: 800
    height: 600
    color: "white"

    Plugin {
        id: osmPlugin
        name: "osm"
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: osmPlugin
        center: QtPositioning.coordinate(36.8065, 10.1815) // Tunis
        zoomLevel: 10
        minimumZoomLevel: 2
        maximumZoomLevel: 18

        /****************************************************************************
         * 1) LEFT‑DRAG MOUSEAREA:                                     Pan by moving *
         ****************************************************************************/
        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton
            hoverEnabled: true

            // track previous mouse pos for this drag
            property real lastX: 0
            property real lastY: 0

            onPressed: {
                lastX = mouse.x
                lastY = mouse.y
            }
            onPositionChanged: {
                // screen → geo for old & new
                const prevGeo = map.toCoordinate(Qt.point(lastX, lastY))
                const currGeo = map.toCoordinate(Qt.point(mouse.x, mouse.y))

                // shift center by (prev - curr)
                map.center.latitude  += (prevGeo.latitude  - currGeo.latitude)
                map.center.longitude += (prevGeo.longitude - currGeo.longitude)

                // update for next move
                lastX = mouse.x
                lastY = mouse.y
            }
        }

        /****************************************************************************
         * 2) WHEELHANDLER:                                      Zoom with wheel *
         ****************************************************************************/
        WheelHandler {
            target: map
            onWheel: wheelEvent => {
                if (wheelEvent.angleDelta.y > 0 && map.zoomLevel < map.maximumZoomLevel)
                    map.zoomLevel += 1
                else if (wheelEvent.angleDelta.y < 0 && map.zoomLevel > map.minimumZoomLevel)
                    map.zoomLevel -= 1
                wheelEvent.accepted = true
            }
        }
        // pan(dx, dy) is a Map API, but here we convert drag → geo‑delta instead :contentReference[oaicite:0]{index=0}
        // WheelHandler is the way to intercept scroll events :contentReference[oaicite:1]{index=1}

        /****************************************************************************
         * 3) RIGHT‑CLICK MOUSEAREA:                    Your custom C++ callback *
         ****************************************************************************/
        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.RightButton
            hoverEnabled: true
            onClicked: {
                const coord = map.toCoordinate(Qt.point(mouse.x, mouse.y))
                cppDialog.handleMapClick(coord)
            }
        }
    }

    /* zoom buttons and map‑type picker (unchanged) */
    Column {
        anchors.top: parent.top
        anchors.right: parent.right
        spacing: 5
        padding: 10

        Button {
            text: "+"
            onClicked:
                if (map.zoomLevel < map.maximumZoomLevel)
                    map.zoomLevel += 1
        }
        Button {
            text: "-"
            onClicked:
                if (map.zoomLevel > map.minimumZoomLevel)
                    map.zoomLevel -= 1
        }

        ComboBox {
            width: 140
            model: map.supportedMapTypes
            textRole: "name"
            onCurrentIndexChanged:
                map.activeMapType = map.supportedMapTypes[currentIndex]
        }
    }
}
