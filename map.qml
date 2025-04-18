import QtQuick 2.15
import QtQuick.Controls 2.15
import QtLocation 5.15
import QtPositioning 5.15

Item {
    id: root
    anchors.fill: parent

    // Propriétés exposées à C++
    property var center: QtPositioning.coordinate(34.0, -6.0) // Valeur par défaut: Maroc
    property real zoomLevel: 10
    property var markers: []
    property var markersToAdd: []

    // Mise à jour automatique lorsque les propriétés changent depuis C++
    onCenterChanged: {
        if (center && center.latitude && center.longitude) {
            map.center = QtPositioning.coordinate(center.latitude, center.longitude)
        }
    }

    onZoomLevelChanged: {
        map.zoomLevel = zoomLevel
    }

    onMarkersToAddChanged: {
        clearMarkers()
        for (var i = 0; i < markersToAdd.length; i++) {
            addMarker(markersToAdd[i])
        }
    }

    Plugin {
        id: mapPlugin
        name: "osm"
        PluginParameter {
            name: "osm.mapping.custom.host"
            value: "https://tile.openstreetmap.org/"
        }
        PluginParameter {
            name: "osm.mapping.providersrepository.disabled"
            value: "true"
        }
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        center: root.center
        zoomLevel: root.zoomLevel

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            property real lastX: 0
            property real lastY: 0
            property bool isDragging: false

            onPressed: {
                lastX = mouse.x
                lastY = mouse.y
                isDragging = false
            }

            onPositionChanged: {
                if (pressed) {
                    var dx = mouse.x - lastX
                    var dy = mouse.y - lastY
                    if (dx * dx + dy * dy > 25) {
                        isDragging = true
                        map.pan(-dx, -dy)
                        lastX = mouse.x
                        lastY = mouse.y
                    }
                }
            }

            onClicked: {
                if (!isDragging) {
                    var coord = map.toCoordinate(Qt.point(mouse.x, mouse.y))
                    if (typeof transportWindow !== 'undefined') {
                        transportWindow.onMapClicked(coord.latitude, coord.longitude)
                    }
                }
            }

            onWheel: {
                if (wheel.angleDelta.y > 0) {
                    map.zoomLevel = Math.min(map.zoomLevel + 0.5, 20.0)
                } else {
                    map.zoomLevel = Math.max(map.zoomLevel - 0.5, 3.0)
                }
            }
        }
    }

    // Modifiez la fonction addMarker
    function addMarker(markerData) {
        var component = Qt.createComponent("Marker.qml")
        if (component.status === Component.Ready) {
            var item = component.createObject(map, {
                coordinate: QtPositioning.coordinate(markerData.latitude, markerData.longitude),
                nom: markerData.destination || ""  // Utilisez 'destination' au lieu de 'nom'
            })
            if (item !== null) {
                map.addMapItem(item)
                markers.push(item)
            } else {
                console.log("Erreur création du marqueur")
            }
        } else {
            console.log("Erreur chargement Marker.qml:", component.errorString())
        }
    }

    function clearMarkers() {
        for (var i = 0; i < markers.length; i++) {
            map.removeMapItem(markers[i])
            markers[i].destroy()
        }
        markers = []
    }

    Rectangle {
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.margins: 20
        width: 50
        height: 50
        radius: 25
        color: "white"
        border.color: "gray"
        opacity: 0.8

        Text {
            anchors.centerIn: parent
            text: "⌂"
            font.pixelSize: 24
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                root.center = QtPositioning.coordinate(34.0, -6.0)
                root.zoomLevel = 10
            }
        }
    }
}
