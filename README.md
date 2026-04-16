部内ロボコンに出場した際のソフトウェアデータになります。

構成としては、足回りが３輪のオムニホイールによる制御、コントローラはスマホアプリの**ESP32_Dabble**を用いています。

```cpp
//オムニホイール制御用の計算関数

void calcpwm(){
  int xval = 252 * GamePad.getXaxisData() / 7;
  int yval = 252 * GamePad.getYaxisData() / 7;

  motorAinput = xval;
  motorBinput = xval * cosf(thetaB) + yval * sinf(thetaB);
  motorCinput = xval * cosf(thetaC) + yval * sinf(thetaC);
}

```
```cpp
//Dabble上で　✕　ボタンが押された時の処理

if(GamePad.isCrossPressed()){
    state = 0;
    motorAinput = 0;
    motorBinput = 0;
    motorCinput = 0;
    Serial.println("stop");
}
```

テストラン動画
<video src="https://github.com/user-attachments/assets/0bf393b1-2884-4c87-a002-765598d3a280
" width="100%" controls></video>




