OKA Class for ROOT
==

ROOTで使うための自作クラス。今のところ```TGraphErrors```を継承してる```OGraph```というクラスが```TGraphErrors```よりも簡単に軸ラベルとプロット範囲を変えれるという機能のみ。初めて自分でクラス追加したので間違いがたくさんあるかも。

#使い方
##ビルド

```Makefile``` の書き方はまだ勉強中。あと```LinkDef.h```の書き方もよくわからない。```OGraph```を使うには、```Makefile```のあるディレクトリで

	make OGraph
	
する (初めてのときは ```mkdir lib``` してから)。すると同じディレクトリに```OH1Dict.cxx```, ```OH1Dict.h```が作られる(邪魔なので別のディレクトリにつくりたいがやり方が分からない)。さらに```lib```以下に```libOGraph.so```がつくられる。このライブラリファイルをROOTで読みこめばよい。

##ライブラリファイルの読み込み
CINTで使うには、```.bashrc```とかに

	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ROOTSYS/lib:$HOME/git/OkaClass/lib

と書いて、```OkaClass/lib```以下をロードできるようにする(ここでは```~/git```以下に```OkaClass```を置いた)。ROOTを開いたら、

	gSystem.Load("libOGraph.so")   

とすればOGraphのライブラリが読み込まれる (```.rootlogon.C``` に書いてもよい)。また、ファイルを直接指定して、

	.L ~/git/OkaClass/lib/libOGraph.so
	
としても行ける？

#クラス
##OH1
TH1Dを継承している。今のところ宣言しただけで追加機能なし。

##OGraph
TGraphErrorsを継承している。
###メソッド
####軸ラベルの変更

	OGraph::SetXTitle(char* titile)
	OGraph::SetYTitle(char* titile)
でX軸、Y軸のラベルを変えられる。```TGraph```とかだと```GetXaxis()->SetTitle("title")```とかしないと行けないので一手間減る。
####プロット範囲の変更
TGraphでの範囲の変更は  
[How to set ranges on axis ? | ROOT](https://root.cern.ch/drupal/content/how-set-ranges-axis)   
の一番下に書いてあるけどとても覚えられたものではないので、分かりやすくした。

	OGraph::SetXRange(Double_t ufirst, Double_t ulast)
	OGraph::SetYRange(Double_t ufirst, Double_t ulast)
でできる。変数```ufirst```とかのuは多分userのu。

#参考リンク
以下の情報を参考にさせて頂きました。
##Official
- [Adding Your Class to ROOT: ClassDef | ROOT](https://root.cern.ch/drupal/content/adding-your-class-root-classdef)
- [Selecting Dictionary Entries: Linkdef.h | ROOT](https://root.cern.ch/drupal/content/selecting-dictionary-entries-linkdefh)
- [Users Manual 第15章 (ウイングアーク１ｓｔ株式会社 さんによる翻訳)](http://www.dw-sapporo.co.jp/technology/658766f830d530a130a430eb7f6e304d5834/root_usersguide_jp/15AddingaClass.pdf)

##Unofficial
- [MyClass [KamonoWiki]](http://www-he.scphys.kyoto-u.ac.jp/member/n.kamo/wiki/doku.php?id=study:software:root:myclass)
- [ROOTに自作クラスを追加する - HongoWiki](http://www-utheal.phys.s.u-tokyo.ac.jp/~yuasa/wiki/index.php/ROOT%E3%81%AB%E8%87%AA%E4%BD%9C%E3%82%AF%E3%83%A9%E3%82%B9%E3%82%92%E8%BF%BD%E5%8A%A0%E3%81%99%E3%82%8B)
- [PukiWiki - memo/root/クラスの追加](http://ribf.riken.jp/~kondo/wiki/index.php?memo%2Froot%2F%A5%AF%A5%E9%A5%B9%A4%CE%C4%C9%B2%C3)
- [ROOT入門-ROOTのマクロで、自作クラスを使う - あやしいむつあい技術](http://d.hatena.ne.jp/kamiogawa/20090430/1241072164)



---


以下メモ。

#To Do的な

- Dictファイルの位置をどうにかしたい
- ライブラリをひとつにまとめたい 
	- ```$ROOTSYS/test```では各々にDictがあってlibも個別にあるのでそれが普通なのかな。
- ```LinkDef.h```はこれでいいのかわからないけど一つで事足りたのでこうしておく。


