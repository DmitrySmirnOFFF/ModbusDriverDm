import QtQml   2.12
import ModbusDriver 1.0


QtObject {

    property alias gFC400: gFC400

//    property ModbusMaster mbMaster: ModbusMaster{
//        id:mbMaster
//        objectName: "Modbus Master 1"
//        /* уже имеются настройки по умолчанию ModbusMaster.cpp*/
//        /* оставим их без изменений */
//        port: "COM7"

//        ModbusRequest{
//            objectName: "Запрос на чтение"
//            periodRx: 500
//            reg: 0
//            quantity: 10
//            GroupRtu1 {
//                id:group1
//            }
//        }
//        Component.onCompleted: {
//            //qmlComplete();
//        }
//    }

    property ModbusClient mbClient: ModbusClient{
        id:mbClient
        objectName: "Modbus Client 1"
        /* уже имеются настройки по умолчанию ModbusMaster.cpp*/
        /* оставим их без изменений */
        //socket: "192.168.0.11:502"
        ModbusRequest{
            objectName: "Запрос r256 q20"
            periodRx: 500
            reg: 256
            quantity: 20
            MbRtu_gFC400{
                id:gFC400
            }
        }
        Component.onCompleted: {
            //console.log(mbClient.socket.toString())
            qmlComplete();
        }
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:1}
}
##^##*/
