
	TOPPERS/ASP Kernel with TECS（Release 1.0.0）
		Toyohashi Open Platform for Embedded Real-Time Systems/
		Advanced Standard Profile Kernel
	  + Embedded Component System

このパッケージは，TOPPERS/ASPカーネル（以下，ASPカーネル）の周辺モジュー
ルを，TECSの仕様に基づいてコンポーネント化したものです．

【ファイルの展開方法】

このパッケージは，ASPカーネルと同様のディレクトリ構成になっていますが，
ASPカーネルから修正を加えていないディレクトリのいくつかを含めていません．

サンプルプログラムを構築する場合には，このパッケージを展開したディレク
トリの下に，以下のソフトウェアを展開（または，シンボリックリンク）して
ください．

	tecsgen		TECSのインタフェースジェネレータ

【構築方法】

サンプルプログラムを構築・動作させる手順は，基本的には，ASPカーネルと同
様です．ASPカーネルのパッケージに含まれる「TOPPERS/ASPカーネル ユーザー
ズマニュアル」の「３．クイックスタートガイド」の節を参照してください．

また，Skyeyeシミュレーション環境を用いる場合には，AT91SKYEYEターゲット
依存部のマニュアル（target/at91skyeye_gcc/target_user.txt）をお読み下さ
い．

【コンポーネント化したモジュール】

○ターゲット非依存部

syssvc/tLogTask: システムログタスク
syssvc/tSerialPort: シリアルインタフェースドライバ
syssvc/tSysLog: システムログ機能

○ターゲット依存部（SkyEye依存部）

target/at91skyeye_gcc/tPutLogSkyeye: システムログの低レベル出力
target/at91skyeye_gcc/tSIOPortSkyeye: シリアルI/Oデバイス（SIO）ドライバ

○サンプルプログラム

sample/tSample: サンプルプログラム

【サンプルの実行方法（skyeye版）】
tecs_package/asp+tecs/

○シンボリックリンク
tecsgen（TECSのインタフェースジェネレータ）にシンボリックリンクを張る

tecs_package/asp+tecs/に移動

・bin/tecsgen.exeを利用する場合
: ln -s ../bin/tecsgen.exe tecsgen.exe 

・自分で構築したtecsgenを利用する場合
: ln -s ../tecsgen tecsgen

tecsgenの構築方法は，tecs_package/README.txt
およびtecs_package/tecsgen/README.txtを参照してください．

○サンプルプログラムのディレクトリ（asp+tecs/sample1_skyeye）に移動
: cd sample1_skyeye
  
○TECSのインタフェースジェネレータの実行

・bin/tecsgen.exeを利用する場合
: make tecs

  注：パーミッションエラーになる場合
     下記のコマンドを実行する
: chmod 500 ../../bin/tecsgen.exe

  注：CPPエラーになる場合
  gccがシンボリックリンクの場合は，MakefileでCPPシンボリックリンク先を指定する必要がある．
  具体的にはMakefileの TECSGEN_CPPを変更する．

 #cygwinのgccがシンボリックリンクの場合は，
 #下記ようにシンボリックリンク先(gcc-3,gcc-4など)を直接指定する必要がある．
 #TECSGEN_CPP = 'gcc-3 -E -D TECS'
 #TECSGEN_CPP = 'gcc-4 -E -D TECS'

・自分で構築したtecsgenを利用する場合
  Makefileの111行目のTECSGENをコメントアウトし，
  114行目辺りのRUBYLIBとTECSGENのコメントを外す．

#tecsgen.rb (ruby + racc)を利用する場合は下記のRUBYLIBとTECSGENの定義を利用する
#RUBYLIB = $(SRCDIR)/tecsgen/tecsgen
#TECSGEN =$(RUBY) $(SRCDIR)/tecsgen/tecsgen/tecsgen.rb -L $(RUBYLIB)

: make tecs

○依存関係の生成
: make depend
  注：コンパイルするにはクロスコンパイル環境（arm-elf*）を整える必要があります．
      http://www.embedded.jp/gnuwing/などで入手できます．
  注：パーミッションエラーになる場合は下記のコマンドを実行する
      chmod 500 ../cfg/cfg/cfg.exe 

○コンパイル
: make

○実行
: skyeye.exe -e asp.exe
  注：tecs_package/bin/skyeye.exeにパスを通す必要がある．
  または
: ../../bin/skyeye.exe -e asp.exe
  注：パーミッションエラーになる場合は下記のコマンドを実行する
      chmod 500 ../../bin/skyeye.exe

○クリーン
・オブジェクトファイルの削除
: make clean

・TECSのインタフェースジェネレータの生成したコード・依存関係の削除
: make realclean

【質問・バグレポート・意見等の送付先】

TECSおよびASPカーネルをより良いものにするためのご意見等を歓迎します．

TECSに関する質問やバグレポート・ご意見等は，TOPPERSユーザズメーリングリスト 
（user@toppers.jp）宛にお願いします．TOPPERS会員は，TOPPERSコンポーネント仕様
WGのメーリングリスト（com-wg@toppers.jp）宛にも投稿できます．

以上
