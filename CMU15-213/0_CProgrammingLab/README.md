## README

cprogramminglab-handout.tar 是原文件，大家可以下载下来自己实现。

cprogramminglab-handout文件夹是我的实现结果

cprogramminglab.pdf 是老师给的介绍实验的pdf，认真阅读，很重要！！！

我们主要实现的是在queue.c这个文件里面，往里面填代码就可以了。

有几点要注意：
1.特别要小心malloc，free，特别是在`q_insert_head`和`q_insert_tail`里面，就算一开始`newh`申请内存成功，但是`newh->value`内存申请失败的话，那么`newh`的内存要回收
2.特别要小心`q==NULL`的情况，基本所有的函数第一句都是判断这个
3.strlen()不含`'\0'`所以申请内存的时候要+1.
