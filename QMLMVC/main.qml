import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ListModel {
        id: fruitModel
        ListElement
        {
            name: "Apple"
            cost: 2.45
        }

        ListElement
        {
            name: "Orange"
            cost: 3.25
        }

        ListElement
        {
            name: "Banana"
            cost: 1.95
        }

        Component
        {
            id: fruitDelegate
            Row
            {
                Rectangle
                {
                    color: "lightgreen"
                    Text {
                        text: name
                    }
                    Text {
                        text: cost + '$'
                    }
                }
            }
        }
    }

    ListView
    {
        anchors.fill: parent
        model: fruitModel
        delegate: fruitDelegate
    }
}
