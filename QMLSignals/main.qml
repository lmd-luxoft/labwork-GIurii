import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Button
    {
        objectName: "myButton"
        text: "Press me!"
        signal buttonClicked(string str)
        x: 10
        y: 20
        onClicked: function()
        {
            buttonClicked("button clicked");
        }
    }

    Text {
        id: _tex
        x: 10
        y: 60
        objectName: "myText"
        text: qsTr("text")
    }
}
