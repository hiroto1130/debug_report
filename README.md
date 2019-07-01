# debug_report
## ブレイクポイントについて  
まず、break point の設定の仕方について。  
設定の仕方は下の画像の様にマウスカーソルを持ってきて左クリックか、break point を設置した行にマウスカーソルを持ってきた後 F9 を押すことで設置できます。  
解除についても同様のやり方で行えます。  
その他の知っておくと便利なものとして
- 一時的にOFF  -> Ctrl + F9、
- 全削除するには  -> Shift + Ctrl + F9  

の二種類があります。  

＊break point 設置例
![](https://github.com/hiroto1130/image_preservation/blob/master/break_point4.png?raw=true)

では、実際にビルドしてみます。 

![](https://github.com/hiroto1130/image_preservation/blob/master/break_point.png?raw=true)

はい、しっかりと止まりました。  
ここから、 F10 を押して行くことでコードの処理を追うことができます。 

![](https://github.com/hiroto1130/image_preservation/blob/master/break_point2.png?raw=true)


一つ処理が進んで a , b , c の値が代入されたのが確認できると思います。  

![](https://github.com/hiroto1130/image_preservation/blob/master/break_point3.png?raw=true)  

もう一つ処理が進み、c = a + b の処理が行われ、c の値が 7 になったのが確認できると思います。  

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




























## Step over/in/outについて  
## 自動変数・ローカル変数ウィンドウについて  
## ウォッチ式について  
## データブレイクポイントについて  
## メモリウィンドウについて  
## コールスタック(呼び出し履歴)について  
## イミディエイトウィンドウについて  
