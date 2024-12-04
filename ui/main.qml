import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Shift Manager ++")

    GridView {
        id: tableView
        anchors.centerIn: parent
        width: parent.width * 0.8
        height: parent.height * 0.6
        model: ListModel {
            ListElement { date: "2024-12-01"; startTime: "09:00"; endTime: "17:00"; earnings: "$120" }
            ListElement { date: "2024-12-02"; startTime: "10:00"; endTime: "18:00"; earnings: "$130" }
            ListElement { date: "2024-12-03"; startTime: "08:00"; endTime: "16:00"; earnings: "$110" }
        }
        cellWidth: tableView.width / 4
        cellHeight: 40
        delegate: Rectangle {
            width: tableView.cellWidth
            height: tableView.cellHeight
            border.color: "black"
            Text {
                text: `${model.date || model.startTime || model.endTime || model.earnings}`
                anchors.centerIn: parent
            }
        }
    }
}
