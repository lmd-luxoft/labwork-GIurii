import QtQuick 2.15
import QtQuick.Window 2.15
import com.luxoft.c005 1.0
import QtQuick.Controls 2.5

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Weather in the city")

    Weather
    {
        id: myWeatherInformer
        city: "Odessa"
        onCurrentWeatherChanged: function(p) {
            infoPanel.text = city + ": " + p;
        }
    }

    Text {
        id: infoPanel
        x: 50
        y: 10
        width: 100
        height: 200
        color: "green"
        text: qsTr("text")
    }

    Button
    {
        x: 50
        y: 50
        text: "Press to force update ewather"
        onClicked: function() {
            myWeatherInformer.forceUpdate();
        }
    }

    Button
    {
        x: 50
        y: 100
        text : "Set to Saint Peterburg"
        onClicked: function() {
            myWeatherInformer.city = "Saint Peterburg"
        }
    }

    Button
    {
        x: 50
        y: 150
        text : "Set to Odessa"
        onClicked: function() {
            myWeatherInformer.city = "Odessa"
        }
    }
}
