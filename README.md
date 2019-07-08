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

![](https://github.com/hiroto1130/image_preservation/blob/master/break%20point/break_point.png?raw=true)   


では、実際にビルドしてみます。     

はい、しっかりと止まりました。   
ここから、 F10,F11 を押して行くことでコードの処理を追うことができます。 
F10,F11でやっていることが少し違うので、この後の step ovre, in ,out で詳しく説明します。   

![](https://github.com/hiroto1130/image_preservation/blob/master/break%20point/break_point2.png?raw=true)  

一つ処理が進んで a , b , c の値が代入されたのが確認できると思います。  

![](https://github.com/hiroto1130/image_preservation/blob/master/break%20point/break_point3.png?raw=true)   

１つ処理が進み、c = a + b の処理が行われ、c の値が 7 になったのが確認できると思います。   

次に、break point の機能の１つの「**書き換え**」についての説明です。   
break point を設置して コードを実行するまでは同じです。  
では、実際に書き換えてみます。  

![](https://github.com/hiroto1130/image_preservation/blob/master/break%20point/break_point2.png?raw=true)  

まず、c = a + b の処理が行われている所までコードを進めます。  

![](https://github.com/hiroto1130/image_preservation/blob/master/break%20point/break_point5.png?raw=true)  

ここでは、a の値を 2 から 5 に変更してみます。  

![](https://github.com/hiroto1130/image_preservation/blob/master/break%20point/break_point6.png?raw=true)  

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

![](https://github.com/hiroto1130/image_preservation/blob/master/step%20ovre%20in%20out/step%20over%20,%20in%20,%20out%201%20.gif?raw=true)  

#### step in について  

step in は step over と同様に１行単位で実行されます。  
しかし、step in は step over と違い、このステップ実行をすると、下のGIFを見てもわかるように、関数の中で使われている関数の中にも入っていくことができます。  
その為、この step in は最もステップ単位が小さいデバッグ方法になります。  
step in のメリットを簡潔に言うと、呼び出し先のプロシージャまで追跡したい場合に便利な点です。  

![](https://github.com/hiroto1130/image_preservation/blob/master/step%20ovre%20in%20out/step%20in.gif?raw=true)  

#### step out について

step out は上の二つよりも使用頻度は落ちますが主にゲーム制作に入ってからは重宝すると思います。  
step out の機能は、今実行している関数の外（呼び出し元）に出るまでプログラムを進めるステップ実行方法です、簡単に言うと「**別関数からメインの関数に戻る**」機能です。  
と、文面で見てもわかりずらいと思うので、GIFを見ていただければわかりやすいと思います。  
step out のメリットは、メインでは無い関数の動作チェックが終わった後に呼び出し元に戻り、確認したい時に役に立ちます。  

![](https://github.com/hiroto1130/image_preservation/blob/master/step%20ovre%20in%20out/step%20out.gif?raw=true)  
  
***
## 	automatic variable・Local variable windowについて  

### automatic variable  について
まず、automatic variable の表示方法について。  
automatic variable はVSのメニューバーにあるデバッグのウィンドウの中に<span style="color: red; ">**デバッグ中のみ**</span>あります。  

上記のやり方がめんどくさい方は「 **ctrl** **+** **alt** **+** **V** **,** **A**」でも出せます、安心してください。もちろん<span style="color: red; ">**デバッグ中のみ**</span>です。

こんな感じですね。  
![](https://github.com/hiroto1130/image_preservation/blob/master/automatic%20variable/automatic%20variable%201.png?raw=true)

次に automatic variable の機能について。  
この機能は Local variable window とよく似ていますが、少し違います。  
具体的には、Local variable window はそのコードに書かれてある変数全てを表示しますが、automatic variable は選択した行の変数とそのひとつ前で使われている変数しか表示しません。  
と、言葉で書いてもわかりずらいので、以下の画像を見るとわかりやすいと思います。  

Local variable window ではすべての変数が表示されていますが...  
![](https://github.com/hiroto1130/image_preservation/blob/master/automatic%20variable/automatic%20variable%203.png?raw=true)  

automatic variable は付近の変数しか表示していません。  
![](https://github.com/hiroto1130/image_preservation/blob/master/automatic%20variable/automatic%20variable%202.png?raw=true)  

最後に automatic variable のメリットについて。  
この、automatic variable の機能のメリットは Local variable window と使い分けができるほか、必要以上の変数を見ることがないため、分かりやすい点です。  


### Local variable windowについて 
まず、Local variable window の表示方法について。  
Local variable window はVSのメニューバーにあるデバッグのウィンドウの中に<span style="color: red; ">**デバッグ中のみ**</span>あります。  

上記のやり方がめんどくさい方は「 **ctrl** **+** **alt** **+** **V** **,** **L**」でも出せます、安心してください。もちろん<span style="color: red; ">**デバッグ中のみ**</span>です。

デバッグ中以外だと...
![](https://github.com/hiroto1130/image_preservation/blob/master/local%20variable%20window/local%20variable%20window%201.png?raw=true)  

デバッグ中だと...
![](https://github.com/hiroto1130/image_preservation/blob/master/local%20variable%20window/local%20variable%20window%202.png?raw=true)   

次に見方について。  
表示すると下のような画面が出てきます。
![](https://github.com/hiroto1130/image_preservation/blob/master/local%20variable%20window/local%20variable%20window%203.png?raw=true)

F10を押して処理をすすめ、すべての値を変数を代入すれば、下の画像の様に値がしっかり代入されていることがわかるともいます。
![](https://github.com/hiroto1130/image_preservation/blob/master/local%20variable%20window/local%20variable%20window%204.png?raw=true)  

最後に Local variable window のメリットについて。  
この機能のメリットは見た通りで、すべての変数に何が入っているのか、を確認することが出来ることです。 

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
![](https://github.com/hiroto1130/image_preservation/blob/master/data%20break%20point/data%20break%20point%20.png?raw=true)  
  
デバッグ中だと選択できます。  
![](https://github.com/hiroto1130/image_preservation/blob/master/data%20break%20point/data%20break%20point%202.png?raw=true)  

#### 書き変わった瞬間に止める設定方法
書き変わった瞬間に止める設定方法について。  
これは、data break point の設定をすれば大丈夫です。  
data break point の window を開くと下のような画面が出てきます。  
ここの記入欄に調べたい code のアドレスを入れる事で、設定できます。     
今回は array[1]　の値が書き換えられた時に止まるように設定します。  

![](https://github.com/hiroto1130/image_preservation/blob/master/data%20break%20point/data%20break%20point%208.png?raw=true)    

設定できると、下のような画面になります。  
![](https://github.com/hiroto1130/image_preservation/blob/master/data%20break%20point/data%20break%20point%20gif%201.png?raw=true)

実際に動かしたものが下のGIF画像です。  

![](https://github.com/hiroto1130/image_preservation/blob/master/data%20break%20point/data%20break%20point%20.gif?raw=true)


#### 条件を決めて止める設定方法
条件を決めて止める設定方法について。  
これは、break point を右クリックし、出てくる画面の中にある条件を選ぶことでできます。  
上記のやり方がめんどくさい方は「**Alt** **+** **F9**」を押した後に「 **C** 」を押すことでも表示できます。  

![](https://github.com/hiroto1130/image_preservation/blob/master/data%20break%20point/data%20break%20point%203.png?raw=true)  
break point を右クリックして、条件を選ぶと...

![](https://github.com/hiroto1130/image_preservation/blob/master/data%20break%20point/data%20break%20point%204.png?raw=true)  
表示された!!

そして、表示された画面の条件にチェックが付いていることを確認し、tureが選択されていることを確認し、白い空白のところに条件を記入します。  
![](https://github.com/hiroto1130/image_preservation/blob/master/data%20break%20point/data%20break%20point%208.png?raw=true)  
この画面になってたら正解です。  

![](https://github.com/hiroto1130/image_preservation/blob/master/data%20break%20point/data%20break%20point%205.png?raw=true)  
無事、設定できればこの画面になります。  


最後に、<span style="color: red; ">**🔴**</span>に<span style="color: white; ">**＋**</span>が入ったマークになっていて、break point window に下記の画像のような表記がされていれば大丈夫です。  
![](https://github.com/hiroto1130/image_preservation/blob/master/data%20break%20point/data%20break%20point%207.png?raw=true)   

実際に動かしてみると、ちゃんと a の値が 0x00000003 で止まっていることが確認できれば大丈夫です。  
![](https://github.com/hiroto1130/image_preservation/blob/master/data%20break%20point/data%20break%20point%206.png?raw=true)  


最後に data break point のメリットについて。  
個人的には、この data break point が一番お世話になる機能だと思っています。  
理由は利便性、汎用誠意が高いところです。  
条件を決めて止めれば、 for文、while文の値を一個一個見なくても、条件を決めて止めれますし。  
書き変わった瞬間止める機能を使えば、バグの詮索作業、どこで参照されているか等がとても楽なります。

***

## メモリウィンドウについて  
まず、memory window の表示方法について。  
memory window はVSのメニューバーにあるデバッグのウィンドウの中に<span style="color: red; ">**デバッグ中のみ**</span>あります。 
これは、いつもの見たくショートカットキーは無いので諦めてください。  

デバッグ中に開いたら、下の方にあります。  

![](https://github.com/hiroto1130/image_preservation/blob/master/memory%20window/memory%20window%202.png?raw=true)  

こんな感じで...

![](https://github.com/hiroto11です。image_preservation/blob/master/memory%20window/memory%20window%203.png?raw=true)  

次に設定方法(使用方法)について。  
実際に memory window を開いて見ると

![](https://github.com/hiroto1130/image_preservation/blob/master/memory%20window/memory%20window%204.png?raw=true)

このような画面が出てきます。  
今回は array の中身が知りたいので &array と打ってアドレスを指定します。  

![](https://github.com/hiroto1130/image_preservation/blob/master/memory%20window/memory%20window%205.png?raw=true)

ENTER を押すとこんな感じ...  

![](https://github.com/hiroto1130/image_preservation/blob/master/memory%20window/memory%20window%206.png?raw=true)  

選択している所にちゃんと、 array の配列の数が入っているのがわかると思います。  

![](https://github.com/hiroto1130/image_preservation/blob/master/memory%20window/memory%20window%207.png?raw=true)  

最後に memory window のメリットについて。  
memory window のメリットは、割り当てられていないメモリ内データ、コード、およびガベージのランダムなビットを含む、メモリ領域ですべてのものが表示されるところです。

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

ちなみに、この<span style="color: red; ">🔴</span>はbreak point の位置、<span style="color: yellow; ">**➡**</span> は現在実行している関数の場所です。  
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

![](https://github.com/hiroto1130/image_preservation/blob/master/Immediate%20window/Immediate%20window.png?raw=true)  
＊メニューバーのデバッグの....

![](https://github.com/hiroto1130/image_preservation/blob/master/Immediate%20window/Immediate%20window1.png?raw=true)  
＊ウィンドウの中にあるImmediate windowを選択したら...

![](https://github.com/hiroto1130/image_preservation/blob/master/Immediate%20window/Immediate%20window2.png?raw=true)  
＊Immediate window が出てきた!!!


次に、Immediate window の使い方について。  
ここでは、基本的な扱い方だけを紹介しています。  

まず、調べたいところでbreak point を設置します。  
![](https://github.com/hiroto1130/image_preservation/blob/master/Immediate%20window/Immediate%20window3.png?raw=true)  

次に調べたい変数、関数名を「?」の後に記入します。  
ここでは、変数 answre の値を調べる為、「?answre」と打っています。  
![](https://github.com/hiroto1130/image_preservation/blob/master/Immediate%20window/Immediate%20window6.png?raw=true)  

では、「Enter」を押して、値を見てみましょう。  
![](https://github.com/hiroto1130/image_preservation/blob/master/Immediate%20window/Immediate%20window7.png?raw=true)  

はい、しっかり、「addition」の計算結果、「12」の値が出てきましたね。  
これは10進数で表示しているのでてきますが、基本は16進数で出てきます。  

最後に、Immediate window のメリットについて。  
Immediateという言葉は「即時の」という意味を持っています。  

Immediate window は、知りたいこと・確認したいことを即時に知ることができるウィンドウです。  
例を挙げるなら多くの変数を持っている関数でこの変数は度の値を持っているのかを確認するのによく使用されます。  







