import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0 //导入控件

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Button{
        text: qsTr("这是一个按钮");
        width: 64
        height: 48
        onClicked: {

        }
    }
}
