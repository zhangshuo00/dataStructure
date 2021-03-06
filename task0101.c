//任务名:1_1 比较下列算法的时间复杂度 
//姓名:张朔
//班级:8班
//学号:2017012067
//日期:2018-09-15
/*
(1) 执行了n次可以用常数1取代，即O（1）
    第二个三重循环语句，基本操作为s += num[k]，执行了n+(n-1)+...+1=n(n+1)/2 次
    再乘以最外层的for循环 n次， 
	保留最高项，去掉最高项的系数，所以时间复杂度为 O（n^3)

(2) 执行了n次，可以用常数1取代， 即O（1） 
	第二个for循环的基本操作为i<=n，O（1）
	两个for循环的结构类似于冒泡排序，执行了n+(n-1)+...+1=n(n+1)/2 次， 
	所以时间复杂度为 O（n^2)
	
(3) main函数中for循环执行了n次，可以用常数1取代，即O（1）
	main函数中调用了solve()函数
	solve()函数的基本操作为 sum += num[i]
	每调用一次solve()，执行n次
	n((n+1)/2+n-(n+1)/2-1)=n^2-n
	保留最高项，所以时间复杂度为 O(n^2) 
	
(4) 第一个for循环执行了n次，可以用常数1取代，即O（1）
	第二个for循环中包含了两个分支语句
	每个分支语句不管对错，均执行1次
	所以第二个for循环执行了3n次
	去掉最高项的系数，所以时间复杂度为 O(n) 
