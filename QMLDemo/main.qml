import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: _rect1
        x:12
        y:12
        width: 76
        height: 96
        color: "lightgreen"
    }
    Rectangle {
        id: _rect2
        x:112
        y:12
        width: 76
        height: 96
        border.color: "lightblue"
        border.width: 4
        radius: 8
        gradient: Gradient {
            GradientStop {position: 0.0; color: "lightblue"}
            GradientStop {position: 1.0; color: "grey"}
        }
    }
    Image {
        id: _company
        source: "Z23b.gif"
        x:200
    }
    Text {
        id: _myText
        text: qsTr("This my first QML")
        width: 100
        height: width/2
        color: "red"
        y: 200
    }
    Button {
        id: _btn
        text: "Press me"
        y:120
        onClicked:
        {
            _myText.text = "clicked!";
            title = "clicked!"
        }
    }
    GreenSquare
    {
        id: _rect3
        x:300
        y:300
        BlueSquare
        {
            width: 50
            y:8
            anchors.fill: parent.left
            anchors.margins: 8
        }
    }


}
