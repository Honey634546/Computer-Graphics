# Mesh Viewer

## 快速开始

### 启动

运行exe文件，会提示
>**teabot?(y/n)?**'

### 茶壶

输入y或者Y，进入茶壶界面

### 其他形状

输入n或者N，会提示
>please input filename

输入obj文件的文件名（带后缀名，如不在当前目录需要输入完整路径）
例如：
>cube.obj

会加载该文件的内容

## 功能

默认图形在界面左下角，只显示了图形的1/4，这里可以按住鼠标右键，然后拖拽，就可以将其拖拽到你想要的位置了（没错，就是正中间）
**画兔子的时候真的很小！**

### 旋转

如果你想自旋，你可以按下**r**，他会绕着自己的y轴进行旋转。

或者按住鼠标左键，然后移动，他就会进行旋转。
不过这里的旋转有点愚蠢（他的原理是根据鼠标的x和y轴的变化来进行对物体的x轴和y轴进行旋转，没有z轴所以在旋转起来会看起来有点怪怪的）。

### 平移

按住鼠标右键，然后移动，他就会跟随你的鼠标移动！

### 放缩

按照习惯，最适合的控制方法就是使用鼠标的滚轮前后滑来实现物品的放缩，但是在这个glut包里并没有轮滑前后滑动进行的事件，只有中间键（轮滑键）的按下和抬起。所以我将其改成了b（big）和s(small).

按下b键，放大。

按下s键，缩小

### 光源位置

使用方向键，你可以改变当前光源的位置。

### 颜色

如果想改变颜色，只需要按下c键。

他就会改变颜色（这个颜色是随机的，你并不能控制）

他会逐渐从当前颜色渐变到目标颜色。
