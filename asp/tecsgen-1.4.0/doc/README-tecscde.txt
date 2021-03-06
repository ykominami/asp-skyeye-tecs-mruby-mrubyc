TECS Component Diagram Editor -- tecscde V0.5.1
						2015.6.8  (V0.5.0)
						2016.5.8  (V0.5.1)
						大山 博司

【概要】

tecscde は、TECS コンポーネント図を編集する GUI ツールです。

tecscde V0.5.1 は、tecsgen V1.3.1.0 以降に対応します。TOPPERS/ASP3 の
CDL ファイルを扱うことができます。

V0.5.* では、既存のセルタイプ (シグニチャ) を CDL ファイルから読み込ん
でセルを配置することができます。既存の CDL ファイルからコンポーネント
図をおこすのに大変便利です。

現在の実装では、コンソールから起動するツールです。tecscde には、2通り
の起動方法があります。1つは CDL ファイルを入力とする方法で、もう1つは
CDE ファイルを入力とする方法です。

【動作環境】

・MinGW 版を使用する場合(Windows)

  tecsgen V1.3.1.7 パッケージの他に、tecscde-MinGW-RT パッケージが追加
  で必要になります。以下のように、同じディレクトリで、解凍します。

   % tar xvzf tecsgen-V1.3.1.7.tgz
   % tar xvzf tecscde-MinGW-RT.tgz
   % cp -pr tecscde/tecsgen/{MinGW,Ruby200,tecsgen.exe,tecscde.exe,tecsmerge.exe} tecsgen/tecsgen/

 Windows 7 SP1 64bit にて動作確認しています。ランタイム部分は 32bit で
 すので、32bit 版でも動作します。

 tecscde.exe のあるディレクトリに実行パスを通すか、パスを指定して起動
 します。実行パスを通すには PATH 環境変数を設定するか、以下のコマンド
 で設定できます（シェルを起動するごとに行う必要があります)。

  % source set_evn.sh
     
 注) cygwin のシェルから起動した場合、拡張子の付いていない tecscde スク
    リプトが起動されることがあります。この場合 X Window 版が起動されてしまいます。
    X サーバーの準備ができていない場合、エラーメッセージの一部は、以下
    のようになります。
      "Cannot open display: :0 (Gtk::InitError)"
    MinGW 版は tecsgen.exe のように、拡張子を付加して起動します。ある
    いは、スクリプト tecscde を削除してください。

 注) cygwin 上の X-Window でも起動できますが、試した限りでは、
    LANG=C.utf-8 を指定しないと、期待したフォントが表示されませんでし
    た。

 注) cygwin 上で MinGW 版 Ruby へのパスを通したうえで tecscde を起動す
    ると、期待したようには動作しません．理由や対処方法が分からない場合、
    tecscde-MinGW-RT.tgz を使用することをお勧めします．

・Linux で使用する場合

 以下が必要です。

   Ruby 1.9 以降
   Ruby Gtk2

 勿論 X Window が前提となっています。
 Ruby Gtk2 は、以下の方法でインストールできます。
    % gem install gtk2

 tecscde のあるディレクトリに実行パスを通すか、パスを指定して起動しま
 す。実行パスを通すには PATH 環境変数を設定するか、以下のコマンドで設
 定できます（シェルを起動するごとに行う必要があります)。

  % source set_evn.sh

 注) 以下の説明で tecscde.exe を起動するように書いていますが、Linux で
     使用する場合には、拡張子 .exe は付加しないようにします。

【CDL ファイルを入力とする方法】

既存の CDL ファイルを入力として編集できます。
この起動方法は、既存の CDL ファイルからコンポーネント図を起こす場合に
適しています。tecsgen を起動するような Makefile がある場合、以下のよう
にすることで起動できます。ただし tecscde への実行パスが通っているもの
とします。

  % make TECSGEN=tecscde.exe tecs

または

  % make TECSGEN_EXE=tecscde.exe tecs

で tecsgen の代わりに tecscde を起動します。Linux 上で使用する場合、拡
張子 .exe を付けないようにします。

tecscde には、tecsgen に対する引数が与えられます。
実行前に、タイムスタンプファイルを消す必要があるかもしれません。
以下のように消すことができます。

  % rm gen/tecsgen.timestamp

【CDE ファイルを入力とする方法】

単に CDE ファイルを指定することで起動できます。
tecscde への実行パスが通っている場合、以下のように起動できます。

  % tecscde.exe file.cde

file.cde の部分は、適宜変更してください。
CDE ファイルは、tecsgen のコマンドラインオプションも記憶しているため、
tecscde では、単に CDE ファイルを指定するだけで編集が可能になります。

CDE ファイルの所在するディレクトリを変更する場合、次の点に注意してください。
CDE ファイルには、読み込んだ CDL ファイルのデータを内部に持っていません。
代わりに CDL ファイルを読み込んだ時のパス (-I) を記憶しています。
このため、読み込んだパスに CDL ファイルがないと、読み込みに失敗します。

この場合、-I でサーチパスを指定しなおして読み込ませます。オプション
--base_dir を指定することで、対応することもできます。

【機能】

・入出力機能
 ・tecsgen コマンド引数による CDL ファイルの編集
 ・CDE ファイルを引数に編集
 ・編集ファイルの CDE ファイルへの保存
 ・PDF ファイルへのエクスポート

・編集機能
 ・セルの設置
 ・セルの削除 (CDL ファイル由来のセルは削除できない．CDE ファイル由来のものは削除可)
 ・セル間の結合 (上記と同様)
 ・セルの属性変更 (上記と同様)
 ・アンドゥー

    shift や ctrl を押しながら選択することで、複数のセルを選択できます。

 注意) CDL ファイル内で定義されたセルや結合を削除や変更することはできません。
     (第一引数として与えられた CDE ファイルで定義されたセルは、削除・変更できます)

・表示機能
 ・ファイル名ごとの色分け表示 (デフォルト)
 ・リージョン(ドメイン)ごとの色分け
 ・セル名の強調表示
 ・拡大・縮小表示

・用紙サイズの指定 (V0.5.* では CDE ファイルを直接編集する必要があります)

【補足】

・CDE ファイルは、CDL ファイルと同じ文法で記述できます。加えて JSON 形
  式で記述された tecsgen コマンドのオプションとセルや結合(join) の位置
  情報を記憶します。
・tecscde は CDL ファイルを読みこむ際に、エラーがあっても読み込みます
  が、Ruby 例外が発生し読み込めないことがあります。
  この場合、予め tecsgen でエラーの無いようにしてから読み込みます。
・CDE ファイルには CDL ファイルと同じ要素を置くことができます。
  しかし、tecscde で編集後保存することができるものは、限られています
  (現時点では　cell 以外は保存できません)。
・CDE ファイルは編集時のパスを記憶します。他へ配布する場合、このことが
  セキュリティホールになる可能性があります。 
・本リリースに同梱の tecsgen は、TECS ジェネレータ V1.3.1.1 と互換性が
  あり、gen ディレクトリ下にコードを生成します。加えて CDE ファイルを
  引数に取ることができます。tecsgen に対するオプションは、CDE ファイル
  に含まれているため、指定する必要がありません。

【tecscde 固有のオプション】

tecscde は、tecsgen のすべてのオプションを受け付けます。
ただし、コード生成に関わるオプションは、指定しても意味がありません。

 --base_dir=dir           base directory (tecscde only)
                          cde ファイルのパスが変わった場合など、base directory を使用しないと、読み込めない場合があります。
                          インポートパスが変わった場合には、-I も指定する必要があります。

 --force-apply-tool_info  force to apply tool_info, even if validation failed. this might cause ruby exception and stop tecscde
                          tecscde は、まだ開発途上なので tool_info に必須の情報を追加する場合があります。
                          古いバージョンの CDE ファイルを読みこむ際に、このオプションを指定する必要があるかもしれません。

 --tate                   vertical (tate) style (tecscde only)  デフォルト
                          新しく作成するセルの受け口、呼び口が、上辺、下辺に設けられます。

 --yoko                   horizontal (yoko) style (tecscde only)
                          新しく作成するセルの受け口、呼び口が、左辺、右辺に設けられます。


【注意点】

少なくとも、以下の問題点があります。

 * CDE ファイルのオーバーライト警告を出さない
 * CDE ファイルの未保存でも終了してしまう
 * 扱えない要素は、多くあります (少なくとも以下は、扱えない)
   * リージョン ･･･   Ruby 例外が発生します
   * アロケータ
   * プラグイン
      through プラグインを適用したファイルも開けますが、うまく繋がっていないセルが見れます
 * セル名のインプレース編集は、実装が不完全です
 * cygwin 版で、何回も起動/終了を繰返すうちに X サーバーがダウンすることを何回か経験しています
   (X サーバーは、OS に近いレベルのものなので、ダウンするのはよろしくない。恐らく Linux 版/MacOS版は、もっと安定していると思います)


