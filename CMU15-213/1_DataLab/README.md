## README

datalab-handout.tar 是原文件，大家可以下载下来自己实现。

datalab-handout文件夹是我的实现结果


1.I need to remove the -m32 flag in the Makefile in order to compile.

### bitXor
a^b=(a&~b)|(~a&b)=~(~(a&~b)&~(~a&b))

### tmin

tmin=0X80000000

### isTmax
其实我们可以很快的发现在计算机里面$T_{max}+1+T_{max}=-1$，也就是说$2T_{max}+1=T_{min}$但是很不凑巧的是$2*(-1)+1=-1$,所以我们为了运用$2T_{max}+1=-1$这个性质的时候必须要把$-1$排除。
但是由于$-1+1=0$但是$T_{max}+1=T_{max}$,所以可以根据这个性质将两者区分开。

### allOddBits
思路：比较直接，我们8个一组取出来，先&在^就很容易解决了。

### negate
应该是最简单的一道题目了，直接运用公式就可以了。

### isAsciiDigit
0-3位用卡诺图
4-7必须为3
剩下全为0

这里一定要分清楚逻辑运算和位运算

### conditional

将x转换为0，1用!!，这很重要

### isLessOrEqual

1.不同号
比较符号位
2.同号的情况
相等？->异或
不想等->**限制符号相同**(容易遗忘)并且相减看符号是什么

### logicalNeg

不断的把高位上面的1往下面移动就可以了。

### howManyBits

