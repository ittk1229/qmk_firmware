# ittk1229

[![Image from Gyazo](https://i.gyazo.com/fb0aefcccf8ab35e5d7c2441a651060f.png)](https://gyazo.com/fb0aefcccf8ab35e5d7c2441a651060f)

## Features

### Default レイヤー

アルファベットを入力するためのレイヤー

-   <kbd>Raise</kbd> を単体で押すと IME を ON に、<kbd>Lower</kbd> を単体で押すと IME を OFF にできる
    -   [QMK Firmware で Raise/Lower と変換/無変換を同じキーに割り当てる - Okapies' Archive](https://okapies.hateblo.jp/entry/2019/02/02/133953)
-   [Home row mods](https://precondition.github.io/home-row-mods) を採用し、ホームポジションにあるキーを長押しすると修飾キーが入力できる
-   <kbd>Alt + Tab</kbd> によるウィンドの切り替えが 1 キーでできる
    -   mac でも alt-tab などの利用を想定
-   <kbd>esc</kbd> を押すと IME も OFF になる
    -   vim で日本語入力をする際、ノーマルモードに戻るたびに IME を OFF する手間を省く
-   [EUCALYN 配列](https://eucalyn.hatenadiary.jp/entry/about-eucalyn-layout)を少し改変した配列になっている
    -   vim で移動に用いる <kbd>h</kbd>, <kbd>j</kbd>, <kbd>k</kbd>, <kbd>l</kbd> を横一列に並べた
    -   日本語を入力する上で比較的登場回数の多い <kbd>n</kbd> を小指から中指の位置に移動した

### Lower レイヤー

数字の入力と移動を行うためのレイヤー

-   <kbd>←</kbd>, <kbd>↓</kbd>, <kbd>↑</kbd>, <kbd>→</kbd>と<kbd>Home</kbd>, <kbd>PageUp</kbd>, <kbd>PageDown</kbd>, <kbd>End</kbd> がそれぞれ横一列に並んでおり、vim ライクに移動ができる

### Raise レイヤー

記号を入力するためのレイヤー

-   役割の近い記号が近くに配置されていて覚えやすい
-   以下のキーが横一列に並んでおり、vim の大きな移動が直感的にしやすい
    -   上下の移動が <kbd>j</kbd>, <kbd>k</kbd> とは逆になっているので注意
    -   <kbd>^</kbd> : 行頭へ移動
    -   <kbd>{</kbd> : 一段落上へ移動
    -   <kbd>}</kbd> : 一段落下へ移動
    -   <kbd>$</kbd> : 行末へ移動

### Adjust レイヤー

その他のキーを割り当てるためのレイヤー

<kbd>Raise</kbd> と <kbd>Lower</kbd> の同時押しで出現

-   ファンクションキーが入力できる
-   LED の切り替えができる
-   Minecraft レイヤーの呼び出し

### Minecraft レイヤー

-   Minecraft の操作で主に使うキーを左手のみに集めた

### OLED display

-   <kbd>CapsLock</kbd> の状態が表示される
-   キーをタイプした回数が表示される

### RGB light

-   レイヤーを切り替えるとバックライトの色が変わる
