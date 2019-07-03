# debug_report
## ブレークポイントについて  
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

１つ処理が進み、c = a + b の処理が行われ、c の値が 7 になったのが確認できると思います。  


次に、break point の機能の１つの「**書き換え**」についての説明です。  
break point を設置して コードを実行するまでは同じです。  
では、実際に書き換えてみます。  

![](https://github.com/hiroto1130/image_preservation/blob/master/break_point2.png?raw=true)  

まず、c = a + b の処理が行われている所までコードを進めます。  

![](https://github.com/hiroto1130/image_preservation/blob/master/break_point5.png?raw=true)  

ここでは、a の値を 2 から 5 に変更してみます。  

![](https://github.com/hiroto1130/image_preservation/blob/master/break_point6.png?raw=true)  

はい、ちゃんと値を変更させた通り、 c の値が 8 になっていますね。  

以上でbreak point の設定に関する簡易的な説明を終わります。  
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
  
***

## 自動変数・ローカル変数ウィンドウについて 

***

## ウォッチ式について  

***

## データブレークポイントについて  
まず、data break point と break point の違いについて。  
一時停止する点を設定することには違いがありませんが、data brack point は break point が処理を確定で止めるのに対し、条件を決めて
正確には data が書き変わった瞬間、特定の値と等しい時、特定の値より大きくなった時などに処理が一時停止する break point です。  

次にdata break point の設定方法について。  
data break point はVSのメニューバーにあるデバッグの中にあるブレークポイントの生成の中にあります。  
しかし、data break point が設定できるのは<span style="color: red; ">**デバッグ中のみ**</span>です。  

このように、デバッグ中じゃない限り選択できません。
![]()
  
デバッグ中だと選択できます。  
![]()

#### 書き変わった瞬間に止める設定方法


#### 条件を決めて止める設定方法




最後に data break point のメリットについて。  
個人的には、この data break point が一番お世話になる機能だと思っています。  
理由は利便性、汎用誠意が高いところです。  
条件を決めて止めれば、 for文、while文の値を一個一個見なくても、条件を決めて止めれますし。  
書き変わった瞬間止める機能を使えば、バグの詮索作業、どこで参照されているか等がとても楽なります。

***

## メモリウィンドウについて  

***
## コールスタック(呼び出し履歴)について 

まず、call stack の表示方法について。  
call stack はVSのメニューバーにあるデバッグのウィンドウの中に<span style="color: red; ">**デバッグ中のみ**</span>あります。  

上記のやり方がめんどくさい方は「 **ctrl** **+** **alt** **+** **c**」でも出せます、安心してください。もちろん<span style="color: red; ">**デバッグ中のみ**</span>です。

通常状態だと...
![](https://github.com/hiroto1130/image_preservation/blob/master/call%20stack/call%20%20stack.png?raw=true)  
もちろん、表示されてません。

デバッグ中だと...
![](https://github.com/hiroto1130/image_preservation/blob/master/call%20stack/call%20%20stack2.png?raw=true)  
表示されてます!!! good!!!


次に call stack の設定について。
call stack のwindow内はこんな感じになっています。  
![](https://github.com/hiroto1130/image_preservation/blob/master/call%20stack/call%20%20stack3.png?raw=true)  

見方として、最初に main関数 があり、その次に multiplication 関数があります。  
基本的に呼ばれた順番に上に積みあがっていきます。  
なので「stack」なんて単語が使われてたり...  

ちなみに、この<span style="color: red; ">**🔴**</span>はbreak point の位置、<span style="color: yellow; ">**➡**</span> は現在実行している関数の場所です。  
![](https://github.com/hiroto1130/image_preservation/blob/master/call%20stack/call%20%20stack5.png?raw=true)  

最後に call stack のメリットについて。
call stack  は簡単に言うと、その時点までにどのような経路をたどって、現在の関数に到達したのかを確認できる機能です。  
上の図ではあまり実感がわかないような気もしますが、これが関数の中に使われている関数に使われている関数に使われ.....
とこれが１０個以上あったらどうでしょう？  
そんな時は call stack を使いましょう。  

***
## イミディエイトウィンドウについて  

まず、Immediate window の表示方法について。  
Immediate window は、VSのメニューバーにあるデバッグのウィンドウの中にあります。  
上記の出し方がめんどくさい方は [ **Ctrl** **+** **alt** **+** **I** ] で出せますのでこちらを推奨。  

![](https://github.com/hiroto1130/image_preservation/blob/master/Immediate%20window.png?raw=true)  
＊メニューバーのデバッグの....

![](https://github.com/hiroto1130/image_preservation/blob/master/Immediate%20window1.png?raw=true)  
＊ウィンドウの中にあるImmediate windowを選択したら...

![](https://github.com/hiroto1130/image_preservation/blob/master/Immediate%20window2.png?raw=true)  
＊Immediate window が出てきた!!!


次に、Immediate window の使い方について。  
ここでは、基本的な扱い方だけを紹介しています。  

まず、調べたいところでbreak point を設置します。  
![](https://github.com/hiroto1130/image_preservation/blob/master/Immediate%20window4.png?raw=true)  

次に調べたい変数、関数名を「?」の後に記入します。  
ここでは、変数 answre の値を調べる為、「?answre」と打っています。  
![](https://github.com/hiroto1130/image_preservation/blob/master/Immediate%20window5.png?raw=true)  

では、「Enter」を押して、値を見てみましょう。  
![](https://github.com/hiroto1130/image_preservation/blob/master/Immediate%20window6.png?raw=true)  

はい、しっかり、「addition」の計算結果、「12」の値が出てきましたね。  
これは10進数で表示しているのでてきますが、基本は16進数で出てきます。  

最後に、Immediate window のメリットについて。  
Immediateという言葉は「即時の」という意味を持っています。  

Immediate window は、知りたいこと・確認したいことを即時に知ることができるウィンドウです。  
例を挙げるなら多くの変数を持っている関数でこの変数は度の値を持っているのかを確認するのによく使用されます。  







