import QtQml   2.12
import ModbusDriver 1.0


ModbusTagGroup{
    objectName: "Группа тэгов преобразователя ПЧ165-400"
    property ModbusTag ready: ModbusTag{
        objectName: "Готовность"
        adress: "MW256.0"
    }
    property ModbusTag work: ModbusTag{
        objectName: "Работа"
        adress: "MW256.1"
    }
    property ModbusTag fault: ModbusTag{
        objectName: "Авария"
        adress: "MW256.2"
    }

    property ModbusTag ia: ModbusTag{
        objectName: "Фазный ток Ia"
        adress: "MW257"
    }
    property ModbusTag ib: ModbusTag{
        objectName: "Фазный ток Ib"
        adress: "MW258"
    }
    property ModbusTag ic: ModbusTag{
        objectName: "Фазный ток Ic"
        adress: "MW259"
    }

    property ModbusTag ua: ModbusTag{
        objectName: "Фазное напряжение Ua"
        adress: "MW264"
    }
    property ModbusTag ub: ModbusTag{
        objectName: "Фазное напряжение Ub"
        adress: "MW265"
    }
    property ModbusTag uc: ModbusTag{
        objectName: "Фазное напряжение Uc"
        adress: "MW266"
    }

    property ModbusTag uDC: ModbusTag{
        objectName: "Напряжение ЗПТ"
        adress: "MW267"
    }

    property ModbusTag start: ModbusTag{
        objectName: "Старт"
        adress: "MW268.0"
    }
    //--------------------------------------------------------
    property ModbusTag tinv1: ModbusTag{
        objectName: "temp1"
        adress: "MW273"
    }
    property ModbusTag tinv2: ModbusTag{
        objectName: "temp2"
        adress: "MW274"
    }
    property ModbusTag g1: ModbusTag{
        objectName: "Старт"
        adress: "MW272.0"
    }
    property ModbusTag f11: ModbusTag{
        objectName: "Старт"
        adress: "MW272.1"
    }
    property ModbusTag f12: ModbusTag{
        objectName: "Старт"
        adress: "MW272.2"
    }
    property ModbusTag f13: ModbusTag{
        objectName: "Старт"
        adress: "MW272.3"
    }
    property ModbusTag f14: ModbusTag{
        objectName: "Старт"
        adress: "MW272.4"
    }
    property ModbusTag f15: ModbusTag{
        objectName: "Старт"
        adress: "MW272.5"
    }

    property ModbusTag g2: ModbusTag{
        objectName: "Старт"
        adress: "MW272.7"
    }
    property ModbusTag f21: ModbusTag{
        objectName: "Старт"
        adress: "MW272.8"
    }
    property ModbusTag f22: ModbusTag{
        objectName: "Старт"
        adress: "MW272.9"
    }
    property ModbusTag f23: ModbusTag{
        objectName: "Старт"
        adress: "MW272.10"
    }
    property ModbusTag f24: ModbusTag{
        objectName: "Старт"
        adress: "MW272.11"
    }
    property ModbusTag f25: ModbusTag{
        objectName: "Старт"
        adress: "MW272.12"
    }


}
