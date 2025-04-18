import QtQuick 2.15
import QtLocation 5.15
import QtPositioning 5.15

MapQuickItem {
    property alias nom: nomText.text
    anchorPoint.x: image.width/2
    anchorPoint.y: image.height

    sourceItem: Column {
        spacing: 5
        Image {
            id: image
            source: "qrc:/marker.png"  // Chemin corrigé
            width: 30
            height: 30
        }
        Rectangle {
            color: "white"
            border.color: "gray"
            radius: 3
            width: nomText.width + 10
            height: nomText.height + 5
            Text {
                id: nomText
                anchors.centerIn: parent
                text: nom
                font.pixelSize: 12
            }
        }
    }
}
