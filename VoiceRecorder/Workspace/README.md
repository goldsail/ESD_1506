# 利用 PSoc 5LP 开发板，实现语音录制传输回放系统

开发板经由串口与电脑连接。在待机模式下（LCD 显示 Ready），使用串口助手发送如下格式的十六进制数据，实现语音的录制、传输、回放等功能。

## 语音录制（0x00）

发送一个字节的十六进制数据 0x00，即可开始语音录制，录制时间不限，录得的数据会实时经由串口返回电脑，波特率为 8kbps，每一帧数据由一个字节的十六进制数据表示（范围是 0 ~ 255）。  

录音时 LCD 显示 Recording。再次发送 0x00，即可停止录制。

## 最后 2 秒语音回放（0x01）

发送一个字节的十六进制数据 0x01，即回放最后录制的 2 秒语音。

## 回放指定语音数据（0x02）

首先发送一个字节的十六进制数据 0x02，其后紧跟 4 个字节的十六进制无符号数，代表将要发送数据的字节数（不含前述 5 字节）。随后跟着这么多个字节的无符号数，代表将要发送的语音信息，波特率为 8kbps，每一帧数据由一个字节的十六进制数据表示（范围是 0 ~ 255）。  

样例：（发送 16 字节的语音数据，共计 16 帧）

```
02 00 00 00 0F 66 67 69 70 65 63 60 71 74 72 73 69 66 63 64 66
```

## 话筒和扬声器直连（0x03）

发送一个字节的十六进制数据 0x00，即可开始将话筒和扬声器的信号直连，时间不限。话筒录到的数据经过 AD 转换后，交由 DA 转换，并实时在扬声器上播放。  

直连时 LCD 显示 Direct Access。  

注：不要将扬声器直接对准话筒，以免引起啸叫。

# 照片

![待机模式显示 Ready](https://i.loli.net/2017/09/01/59a914b10a1fc.jpg)