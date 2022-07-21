# Born2beRoot

## ハッシュ値の算出方法

`shasum`コマンドを使う。
この課題で使用したvdiファイル名が`debian.vdi`だった場合。

```bash
shasum debian.vdi
```

このコマンドを打つことで、`debian.vdi`のハッシュ値を算出でき、今回の課題ではこのハッシュ値を`signature.txt`書いて提出する。

課題提出後に`signature.txt`に記入する用のハッシュ値の算出に利用したVMを少しでも触ってしまと、ハッシュ値の値が変わってしまうことには注意が必要。

## レビュー項目

### Project overview

- 仮想マシンはどのように機能するのか。</br>
  仮想マシンとは、仮想化技術を利用して、コンピューター内にもうひとつのコンピューターを再現する技術のこと。ホストマシンとゲストマシン（仮想マシン）とを仮想的に切り分けることが可能になる。OS自体を破壊しかねないスクリプトやウイルスに感染する危険性の高いテストを行うときに、仮想マシンを使うことでホストマシンに影響を及ぼすことなく、安全にテストを行うことができる。

- CentOSとDebianの基本的な違い。</br>
  Linuxの系統がそもそも違う。CentOSはFedoraという系統のOSであり、 Fedora系とDebian系という時点でOSの系統が違う。
  [参照](https://gigazine.net/news/20060827_linux_distributions)</br>
  Fedora系とDebian系の大きな違いはパッケージマネージャーである。Fedoraはrpmを、Debianはaptをパッケージ管理に使用している。</br>
  その他にも、CentOSは有償のRHEL(Red Hat Enterprise Linux)から商標を除去しており、無償を実現しているなどの特徴もある。

- 仮想マシンの使用目的。</br>
  **「仮想マシンはどのように機能するのか。」** 参照。

- aptitudeとaptの違いは何か。また、APPArmorとは何か。</br>
  aptはaptitudeの派生、進化版。aptitudeはインストールや削除したいパッケージを対話的に選ぶことができ、aptよりもよりユーザーフレンドリー（人によると思いますが）でグラフィカルな方法でパッケージをマネジメントすることができる。</br>
  ユーザがプロセス、ファイル、システムデバイスといったリソースへアクセスする権限を全て自由に制御できず、管理者から一定の強制を受ける、強制アクセス制御(MAC)を実行するためのプログラムがAPPArmorである。</br>
  APPArmorと似たものとして、SELinuxがある。APPArmorはUbuntuやSUSE Linux、SELinuxはRHELやCentOSなどで主に使われている。

## 用語解説

### aptitudeとaptの違い

### viとvimの違い

vi = vimではない。
viの由来はvisual editor、vimの由来はvisual editor improvedである。すなわち、vimはviの改良版という認識で問題ない。
今回は、viの初期設定のままでは使いづらいため、vimをインストールして使うことにする。

### sudoとsuの違い

sudoはそのユーザの権限でプログラムを実行するコマンドである。特定のユーザにとあるコマンドのみ root 権限で実行させたい場合に便利。sudoコマンドを使用する際はrootのパスワードを知っている必要はなく、そのユーザのパスワードを知っていればよい。

suは他のユーザにスイッチする管理系のコマンドである。`$ su`でrootユーザに切り替えることができる。この際に、rootのパスワードを知っていることと、そのユーザがrootユーザに切り替えることが許可されている必要がある。

参照: [sudoとsuの違い](http://tooljp.com/windows/chigai/html/Linux/sudo-su-chigai.html)

## 初期セットアップ

VMを作成し、ホストOSのターミナルから操作できるようにするにはこちらの動画を見てください。

[Born2beRoot初期セットアップ](B2B_setup.mp4)

### vim、sudoのインストール

まず初めに、`apt install`コマンドを実行するためにrootユーザに切り替える。

```terminal
$ su

# apt install vim sudo
```

### /sbin にパスを通す

adduser等の管理システムコマンドがあるディレクトリsbinには最初は環境パスが通っていないため、パスを通す。

```terminal
# echo 'export PATH="$PATH:/sbin:/usr/sbin:usr/local/sbin"' >> ~/.bashrc

# source ~/.bashrc
```

### sudoグループにユーザを追加

sudoグループにユーザを追加する。

```terminal
# adduser <username> sudo
```

sudoグループにユーザが正常に追加されたかを確認する。

```terminal
# getent group sudo
```

変更を反映するために再起動する。

```terminal
# systemctl reboot
```

### 日本語の文字化けを修正する

この項目はdebianのインストール時に言語に日本語を選んだ人のみが行う必要がある。

```terminal
# echo 'case $TERM in
    linux) LANG=C ;;
    *) LANG=ja_JP.UTF-8 ;;
esac' >> /etc/bash.bashrc

# source /etc/bash.bashrc
```

ここで、`TERM`とは端末種別のことである。例えばMacの場合は

```terminal
# echo $TERM
xterm-256color
```

であり、ターミナルの種類はxterm-256colorである。しかし、今回のdebianの場合は以下のようになる。

```terminal
# echo $TERM
linux
```

ターミナルの種類がlinuxのときは`LANG=C`、つまり英語表記に、それ以外の時は`LANG=ja_JP.UTF-8`、つまり日本語表記にしてね、ということである。
実際、VirtualBoxからdebianにログインすると英語表記になるが、Macのターミナルからログインすると日本語表記になる。
