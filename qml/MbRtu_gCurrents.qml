import QtQml   2.12
import ModbusDriver 1.0


ModbusTagGroup{
    objectName: "Группа фазных токов"
    property ModbusTag tag1: ModbusTag{
        objectName: "Ток фазы A"
        adress: "MW0"
    }
    property ModbusTag tag2: ModbusTag{
        objectName: "Ток фазы B"
        adress: "MW1"
    }
    property ModbusTag tag3: ModbusTag{
        objectName: "Ток фазы С"
        adress: "MW2"
    }
}
