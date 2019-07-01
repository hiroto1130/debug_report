# debug_report
## ブレイクポイントについて  
まず、break point の設定の仕方について。  
設定の仕方は下の画像の様にマウスカーソルを持ってきて左クリックか、break point を設置した行にマウスカーソルを持ってきた後 F9 を押すことで設置できます。  
解除についても同様のやり方で行えます。  
その他の知っておくと便利なものとして

|名前|振り当てキー|
|:-|:-|
|設置|F9|
|一時的にOFF|Ctrl + F9|
|全削除| Shift + Ctrl + F9 |

の二種類があります。  

＊break point 設置例
![](https://github.com/hiroto1130/image_preservation/blob/master/break_point4.png?raw=true)

では、実際にビルドしてみます。   

![](https://github.com/hiroto1130/image_preservation/blob/master/break_point.png?raw=true)

はい、しっかりと止まりました。  
ここから、 F10,F11 を押して行くことでコードの処理を追うことができます。 
F10,F11でやっていることが少し違うので、この後の step ovre, in ,out で詳しく説明します。  


![](https://github.com/hiroto1130/image_preservation/blob/master/break_point2.png?raw=true)


一つ処理が進んで a , b , c の値が代入されたのが確認できると思います。  

![](https://github.com/hiroto1130/image_preservation/blob/master/break_point3.png?raw=true)  

mazu,つ処理が進み、c = a + b の処理が行われ、c の値が 7 になったのが確認できると思います。  

***

次に、break point の機能の１つの「**書き換え**」についての説明です。  
break point を設置して コードを実行するまでは同じです。  
では、実際に書き換えてみます。  

![](https://github.com/hiroto1130/image_preservation/blob/master/break_point2.png?raw=true)  

まず、c = a + b の処理が行われている所までコードを進めます。  

![](https://github.com/hiroto1130/image_preservation/blob/master/break_point5.png?raw=true)  

ここでは、a の値を 2 から 5 に変更してみます。  

![](https://github.com/hiroto1130/image_preservation/blob/master/break_point6.png?raw=true)  

はい、ちゃんと値を変更させた通り、 c の値が 8 になっていますね。  

以上でかbreak point の設定に関する簡易的な説明を終わります。  
これが出来れば、デバッグをする際にとても便利です。  

では本題の、break point について。  
berak point は簡単に言えば「**実行されているコードを一時的に止めて値を書き換え、確認をすることが出来る機能**」です。  

***

## Step over/in/outについて

まず、ステップ実行について説明します。  
上のブレイクポイントで行った F10,F11 で一行ずつ処理を見ていくやつです。  
詳しくは、プログラムを一時停止させたあと、プログラムを１行ずつ実行させながら変数などの動きを見ていくという方法です。  
ステップ実行には3種類あり。  

|名前|振り当てキー|
|:-|:-|
|step over|F10|
|step in|F11|
|step out|Shift + F11|

の3種類です。以下、これらの詳細説明になります。  

#### step over について  

step over は１行単位で実行されます、しかし関数があった場合その関数を実行して次の行に移行します。  
関数の内部に入らずそれを飛ばすため「 over 」って言うのかな？
上の文でよくわからなかった場合は下のGIFを見てみてください。  
main の中に複数の関数が入っているのにその関数には飛ばずに処理が行われていることがわかると思います。  
step over を使うことのメリットを簡潔に言うとは、呼び出し先のプロシージャまで追跡する必要がなく、ブレークポイントの設定されたプロシージャ内だけを追跡したい場合に便利な点です。


![](https://github.com/hiroto1130/image_preservation/blob/master/step%20over%20,%20in%20,%20out%201%20.gif?raw=true)  

#### step in について  

step in は step over と同様に１行単位で実行されます。  
しかし、step in は step over と違い、このステップ実行をすると、下のGIFを見てもわかるように、関数の中で使われている関数の中にも入っていくことができます。  
その為、この step in は最もステップ単位が小さいデバッグ方法になります。  
step in のメリットを簡潔に言うと、呼び出し先のプロシージャまで追跡したい場合に便利な点です。  

![](https://github.com/hiroto1130/image_preservation/blob/master/step%20in.gif?raw=true)  

#### step out について

step out は上の二つよりも使用頻度は落ちますが主にゲーム制作に入ってからは重宝すると思います。  
step out の機能は、今実行している関数の外（呼び出し元）に出るまでプログラムを進めるステップ実行方法です、簡単に言うと「**別関数からメインの関数に戻る**」機能です。  
と、文面で見てもわかりずらいと思うので、GIFを見ていただければわかりやすいと思います。  
step out のメリットは、メインでは無い関数の動作チェックが終わった後に呼び出し元に戻り、確認したい時に役に立ちます。  

![](https://github.com/hiroto1130/image_preservation/blob/master/step%20out.gif?raw=true)  
  
## 自動変数・ローカル変数ウィンドウについて 





















## ウォッチ式について  
## データブレイクポイントについて  
## メモリウィンドウについて  
## コールスタック(呼び出し履歴)について  
## イミディエイトウィンドウについて  
