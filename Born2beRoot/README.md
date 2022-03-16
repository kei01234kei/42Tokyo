# Born2beRoot

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

[Born2beRoot初期セットアップ](Born2beRoot初期セットアップ動画.mp4)

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
