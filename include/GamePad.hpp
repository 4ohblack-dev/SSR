#pragma once

//bluetooth接続を初期化し、ESP32のdabbleライブラリを使用して入力を処理するための関数を含む名前空間を定義する

#include <DabbleESP32.h>

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

namespace ble {

auto beginConnection(const std::__cxx11::string bleName) -> void {        //指定された名前でbluetooth接続を初期化する
    Dabble.begin(bleName);
}

auto inputProcess() -> void {                       //ゲームパットの入力を処理
    Dabble.processInput();
}

namespace gamePad {

enum class Button {                                 //様々なゲームパッドボタンを表す列挙型Button
    None,
    Up,
    Down,
    Left,
    Right,
    Start,
    Select,
    Triangle,
    Circle,
    Cross,
    Square,
};

auto pressedButton() -> Button {                                                //どのゲームパッドボタンが押されたかを確認し、対応する列挙値を返す
    if (GamePad.isUpPressed()) {
        return Button::Up;
    }
    else if (GamePad.isDownPressed()) {
        return Button::Down;
    }
    else if (GamePad.isLeftPressed()) {
        return Button::Left;
    }
    else if (GamePad.isRightPressed()) {
        return Button::Right;
    }
    else if (GamePad.isStartPressed()) {
        return Button::Start;
    }
    else if (GamePad.isSelectPressed()) {
        return Button::Select;
    }
    else if (GamePad.isTrianglePressed()) {
        return Button::Triangle;
    }
    else if (GamePad.isCirclePressed()) {
        return Button::Circle;
    }
    else {
        return Button::None;
    }
}

}

}