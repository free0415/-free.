#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <conio.h>
clock_t start,stop;
double duration;
int n=0,i=0,j=0,k=0,b=0,speed,d,temp,cnn=0,N,p=0,L=0,R=0,a[100];
char c,ch;
void selectSpeed();//选择速度 
void handleSelectSpeed(char c);//处理所选择的速度 
void selectSortBy();//选择升降序 
void handleSelectSortBy(char c);//处理所选择的升降序
void selectAlg1();//选择算法（升序） 
void handleSelectAlg1(char c);//处理所选择的算法（升序） 
void selectAlg2();//选择算法（降序） 
void handleSelectAlg2(char c);//处理所选择的算法（降序）
void bubleSort1(int*a, int N);//冒泡排序（升序） 
void bubleSort2(int*a, int N);//冒泡排序（降序）
void selectSort1(int*a,int N);//选择排序（升序） 
void selectSort2(int *a,int N);//选择排序（降序）
void fastSort1(int left,int right,int *a);//快速排序（升序） 
void fastSort2(int left,int right,int *a);//快速排序（降序） 
void clockFastsort1(int left,int right,int *a);//对快速排序（升序）计时 
void clockFastsort2(int left,int right,int *a);//对快速排序（降序）计时
void blnsertsort1(int *a,int N);//插入排序（升序） 
void blnsertsort2(int *a,int N);//插入排序（降序）
void merge1(int *a,int L,int M,int R);//升序归并处理 
void merge2(int *a,int L,int M,int R);//降序归并处理
void mergeSort1(int *a,int L,int R);//归并排序（升序） 
void mergeSort2(int *a,int L,int R);//归并排序（将序）
void clockMergesort1(int *a,int L,int R);//对归并排序（升序）计时 
void clockMergesort2(int *a,int L,int R);//对归并排序（降序）计时
void selectExit();//选择退出菜单
void handleSelectExit(char c);//处理选择退出菜单 
void toExit();//退出程序 

/******************************** 
函数名：main
函数功能：显示欢迎界面并录入数据 
函数输入参数：无 
函数返回值：无 
作者：胡锐 
**********************************/
int main(void){
	system("cls");//清除屏幕上显示的信息
	system("color  F0");//设置屏幕背景色为亮白色、前景色为黑色
		printf("\n");
		printf("        ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	    printf("        ┃            WELCOME!            ┃\n"); 
	    printf("        ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
	    printf("        ┃                                ┃\n");
		printf("        ┃   欢迎使用Hello world排序软件  ┃\n");	
  		printf("        ┃                                ┃\n");
		printf("        ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
		printf("\n       温馨提示：软件支持暂停/继续排序的功能\n      您可以在排序过程中按下SPACE键来暂停/继续\n\n");
		printf("\n            请按下ENTER键进入下一界面\n\n");
		getchar( );
		fflush(stdin);//清空输入缓冲区
		system("cls");//清除屏幕上显示的信息
		printf("\n请输入您要排序数据的个数：\n"); 
		scanf("%d",&N);//确定N值便于后续排序
		printf("\n请输入您要排序的数据(%d个)：\n",N);
		for(i=0;i<N;i++) scanf("%d",&a[i]);//录入数据数组a 
		fflush(stdin);
		selectSpeed();//引用选择速度函数  
}


/******************************** 
函数名：selectSpeed
函数功能：显示速度选择菜单 
函数输入参数：无  
函数返回值：无 
作者：胡锐 
**********************************/
void selectSpeed(){
	system("cls");//清除屏幕上显示的信息
	printf("\n");
	printf("        ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
 	printf("        ┃         速度选择菜单         ┃\n"); 
 	printf("        ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
 	printf("        ┃            1.高速            ┃\n");
	printf("        ┃            2.中速            ┃\n");	
	printf("        ┃            3.低速            ┃\n");
	printf("        ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
	printf("        ┃          4.返回上一级        ┃\n");	
	printf("        ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
	printf("\n          请按下相应数字键并回车完成操作\n");
	c=getchar( ); 	
	fflush(stdin);//清空输入缓冲区
	handleSelectSpeed(c); //引用处理所选择速度的函数 
} 

/******************************** 
函数名：handleSelectSpeed
函数功能：处理所选择的速度 
函数输入参数：字符c 
函数返回值：无 
作者：胡锐 
**********************************/	
void  handleSelectSpeed(char c){
	switch(c)
{
		case '1':speed=500;selectSortBy();break;//设定高速为500ms的延迟，并引用显示排序方式菜单函数 
		case '2':speed=1250;selectSortBy();break;//设定中速为1250ms的延迟 ，并引用显示排序方式菜单函数
		case '3':speed=2000;selectSortBy();break;//设定低速为2000ms的延迟 ，并引用显示排序方式菜单函数
		case '4':main();break;//返回主菜单				
		default:printf("您的输入有误！请重试:\n");c=getchar( );fflush(stdin);handleSelectSpeed(c);//递归式容错性处理 
		}
}

/******************************** 
函数名：selectSortBy
函数功能：显示排序方式菜单 
函数输入参数：无  
函数返回值：无 
作者：胡锐 
**********************************/
void selectSortBy(){
	system("cls");//清除屏幕上显示的信息 
	printf("\n");
	printf("        ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
 	printf("        ┃         排序方式选择菜单        ┃\n"); 
 	printf("        ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
 	printf("        ┃            1.升序排序           ┃\n");
	printf("        ┃            2.降序排序           ┃\n");
	printf("        ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");	
	printf("        ┃            3.返回上一级         ┃\n");
	printf("        ┃            4.退出程序           ┃\n");	
	printf("        ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
		printf("\n          请按下相应数字键并回车完成操作\n");
		c=getchar( ); 	
		fflush(stdin);//清空输入缓冲区
		handleSelectSortBy(c);//引用处理排序方式子菜单函数 
}	

/******************************** 
函数名：handleSelectSortBy
函数功能：处理排序方式子菜单 
函数输入参数：字符c 
函数返回值：无 
作者：胡锐 
**********************************/	
void  handleSelectSortBy(char c){
	switch(c)
{
			case '1':selectAlg1();break;//引用处理升序算法函数 
			case '2':selectAlg2();break;//引用处理降序算法函数
			case '3':selectSpeed();break;//引用选择速度函数
			case '4':toExit();break;//引用退出程序函数
			default:printf("您的输入有误！请重试:\n");c=getchar( );fflush(stdin);handleSelectSortBy(c);//递归式容错性处理 
		}
}	

/******************************** 
函数名：selectAlg1
函数功能：显示升序算法 
函数输入参数：数组 数据个数  
函数返回值：无 
作者：胡锐 
**********************************/		
void selectAlg1( ){
	system("cls"); //清除屏幕上显示的信息
		printf("\n");
		printf("        ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	 	printf("        ┃           算法选择菜单           ┃\n"); 
	 	printf("        ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
	 	printf("        ┃            1.冒泡排序            ┃\n");
		printf("        ┃            2.选择排序            ┃\n");	
		printf("        ┃            3.快速排序            ┃\n");
		printf("        ┃            4.插入排序            ┃\n");
		printf("        ┃            5.归并排序            ┃\n");
		printf("        ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
		printf("        ┃            6.返回上一级          ┃\n");
		printf("        ┃            7.退出程序            ┃\n");			
		printf("        ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
		printf("\n          请按下相应数字键并回车完成操作\n");
		c=getchar( ); 	
		fflush(stdin);//清空输入缓冲区
		handleSelectAlg1(c);//引用处理升序算法子菜单的函数	
}

/******************************** 
函数名：handleSelectAlg1
函数功能：处理升序算法子菜单 
函数输入参数：字符c 
函数返回值：无
作者：胡锐  
**********************************/	
void handleSelectAlg1(char c){
	switch(c)
{
			case '1':bubleSort1(a,N);break;//引用冒泡排序函数
			case '2':selectSort1(a,N);break;//引用选择排序函数
			case '3':clockFastsort1(0,N-1,a);break;	//引用快速排序函数					
			case '4':blnsertsort1(a,N);break;//引用插入排序函数
			case '5':clockMergesort1(a,L,R);break;//引用归并排序函数
			case '6':selectSortBy();break;//引用显示排序方式菜单函数
			case '7':toExit();break;//引用退出程序函数
			default:printf("您的输入有误！请重试:\n");c=getchar( );fflush(stdin);handleSelectAlg1(c);//递归式容错性处理 
		}
}
			
/******************************** 
函数名：selectAlg2
函数功能：显示降序算法 
函数输入参数：数组 数据个数 
函数返回值：无 
作者：胡锐 
**********************************/
void selectAlg2( ){
		system("cls");//清除屏幕上显示的信息
		printf("\n");
		printf("        ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	 	printf("        ┃           算法选择菜单           ┃\n"); 
	 	printf("        ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
	 	printf("        ┃            1.冒泡排序            ┃\n");
		printf("        ┃            2.选择排序            ┃\n");	
		printf("        ┃            3.快速排序            ┃\n");
		printf("        ┃            4.插入排序            ┃\n");
		printf("        ┃            5.归并排序            ┃\n");
		printf("        ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
		printf("        ┃            6.返回上一级          ┃\n");
		printf("        ┃            7.退出程序            ┃\n");			
		printf("        ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
		printf("\n          请按下相应数字键并回车完成操作\n");	
		c=getchar( );
		fflush(stdin);//清空输入缓冲区
		handleSelectAlg2(c);//引用处理降序算法子菜单的函数 
}

/******************************** 
函数名：handleSelectAlg2； 
函数功能：处理降序算法子菜单 
函数输入参数：字符c 
函数返回值：无 
作者：胡锐 
**********************************/	
void handleSelectAlg2(char c){
	switch(c)
{
			case '1':bubleSort2(a,N);break;//引用冒泡排序函数
			case '2':selectSort2(a,N);break;//引用选择排序函数
			case '3':clockFastsort2(0,N-1,a);break;	//引用快速排序函数					
			case '4':blnsertsort2(a,N);break;//引用插入排序函数
			case '5':clockMergesort2(a,L,R);break;//引用归并排序函数
			case '6':selectSortBy();break;//引用显示排序方式菜单函数
			case '7':toExit();break;//引用退出程序函数
			default:printf("您的输入有误！请重试:\n");c=getchar( );fflush(stdin);handleSelectAlg2(c);//递归式容错性处理 
		}
}

/******************************** 
函数名：bubleSort1
函数功能：进行升序的冒泡排序 
函数输入参数：数组 数据个数  
函数返回值：无 
作者：胡锐 
**********************************/	
void bubleSort1(int *a, int N){
	system("cls");//清除屏幕上显示的信息
		printf("原始数据:\n"); 
		for(b=0;b<N;b++) printf("%d  ",a[b]);//输出原始数据
		printf("\n\n");
		Sleep(speed);
		start=clock();//开始计时 		
	    for(j=0;j<N;j++) {//两个for循环，每次取出一个元素跟数组的其他元素比较，将最大的元素排到最后。	
	    	int flag=0;
	        for(i=0;i<N-j-1;i++) { //外循环一次，就排好一个数，并放在后面，所以比较前面n-j-1个元素即可
	            if(a[i]>a[i+1]) {
	                temp=a[i];
	                a[i]=a[i+1];
	                a[i+1]=temp;
	        		flag=1;
	            }      
	        }
			if(flag==0) break;//未进行排序则不输出
			if (kbhit()) system("pause");//检测是否按键来暂停/继续
			printf("第%d步:\n",j+1);
			for(k=0;k<N;k++){printf("%d  ",a[k]);}
			printf("\n\n");
			Sleep(speed);		  		       		
	} 	
			Sleep(speed);
			stop=clock();//结束计时 
			duration=(double)(stop-start)/CLK_TCK;
			printf("本次排序共耗时: %.0f(秒)\n\n",duration);
		 	system("pause");
		 	selectExit();//引用选择退出菜单函数 
}

/******************************** 
函数名：bubleSort2
函数功能：进行降序的冒泡排序 
函数输入参数：数组 数据个数  
函数返回值：无 
作者：胡锐 
**********************************/
void bubleSort2(int *a, int N){
	system("cls");//清除屏幕上显示的信息
		printf("原始数据:\n");
		for(b=0;b<N;b++) printf("%d  ",a[b]);//输出原始数据
		printf("\n\n");
		Sleep(speed);
		start=clock();//开始计时								
	    for(j=0;j<N-1;j++) {//两个for循环，每次取出一个元素跟数组的其他元素比较，将最小的元素排到最后。
	    	int flag=0;
	        for(i=0;i<N-j-1;i++) {//外循环一次，就排好一个数，并放在后面，所以比较前面n-j-1个元素即可
	            if(a[i]<a[i+1]) {
	                temp=a[i];
	                a[i]=a[i+1];
	                a[i+1]=temp;
	                flag=1;
	            }      
	        }
			if(flag==0) break;//未进行排序则不输出 
			if (kbhit()) system("pause");//检测是否按键来暂停/继续
			printf("第%d步:\n",j+1);
			for(k=0;k<N;k++){printf("%d  ",a[k]);}
			printf("\n\n");
			Sleep(speed);
		} 
			Sleep(speed);
			stop=clock();//结束计时
			duration=(double)(stop-start)/CLK_TCK;
			printf("本次排序共耗时: %.0f(秒)\n\n",duration);
		 	system("pause");
		 	selectExit();//引用选择退出菜单函数  
}

/******************************** 
函数名：selectSort1
函数功能：升序的选择排序 
函数输入参数：数组 数据个数 
函数返回值：无
作者：危琪  
**********************************/	
void selectSort1(int *a,int N){
	system("cls");//清除屏幕上显示的信息
	Sleep(speed);
	start=clock();//开始计时	
	printf("原始数据:\n");//输出原始数据
	for(i=0;i<N;i++) printf("%d  ",a[i]);
	printf("\n\n");
	Sleep(speed);
	for(i=0;i<N-1;i++){
		d=i;//先使d记录排序范围内的第一个元素的位置
		int flag=0; 
    	for(j=i+1;j<N;j++){//找出最大元素，由d记录
			if(a[d]>a[j]){
    			d=j;
				}
			}
    		if(d!=i){//如果排序范围的第一个元素（即第i个元素）不是最大值，则将最大元素与第i个元素对调 
			temp=a[d];
			a[d]=a[i]; 
			a[i]=temp;
			flag=1;
			}
			if(flag==0) break;//未进行排序则不输出
			if (kbhit()) system("pause");//检测是否按键来暂停/继续
			printf("第%d步\n",i+1);
			int i=0;	
			for(i=0;i<N;i++)
			printf("%d  ",a[i]);
			printf("\n\n");
			Sleep(speed);	
	}
	stop=clock();//结束计时 
	duration=(double)(stop-start)/CLK_TCK;
	printf("本次排序共耗时: %.0f(秒)\n\n",duration);
	system("pause");
	selectExit();//引用选择退出菜单函数  
}

/******************************** 
函数名：selectSort2
函数功能：降序的选择排序 
函数输入参数：数组 数据个数 
函数返回值：无
作者：危琪  
**********************************/	
void selectSort2(int *a,int N){
	system("cls");//清除屏幕上显示的信息
	Sleep(speed);
	start=clock();//开始计时	
	printf("原始数据:\n");//输出原始数据
	for(i=0;i<N;i++) printf("%d  ",a[i]);
	printf("\n\n");
	Sleep(speed);
	for(i=0;i<N-1;i++){//n个数据需进行n-1趟比较
		d=i;//先使d记录排序范围内的第一个元素的位置
		int flag=0;
    	for(j=i+1;j<N;j++){//找出最小元素，由d记录
			if(a[d]<a[j]){
    			d=j;
				}
			}
    		if(d!=i){//如果排序范围的第一个元素（即第i个元素）不是最小值，则将最小元素与第i个元素对调 
			temp=a[d];
			a[d]=a[i]; 
			a[i]=temp;
			flag=1;
			}
			if(flag==0) break;//未进行排序则不输出
			if (kbhit()) system("pause");//检测是否按键来暂停/继续
			printf("第%d步\n",i+1);
			int i=0;	
			for(i=0;i<N;i++)
			printf("%d  ",a[i]);
			printf("\n\n");
			Sleep(speed);	
	}
	stop=clock();//结束计时 
	duration=(double)(stop-start)/CLK_TCK;
	printf("本次排序共耗时: %.0f(秒)\n\n",duration);
	system("pause");
	selectExit();//引用选择退出菜单函数  
}

/******************************** 
函数名：fastSort1
函数功能：升序的快速排序
函数输入参数：数组 数据个数
函数返回值：无
作者：秦浩辰 
**********************************/
void fastSort1(int left,int right,int *a){	
    int flag=0;
    i=left;//从数组的最左边和最右边分别开始寻找比最左大的数，并分别放到左边和右边
    j=right;
    temp=a[left];
    while(i<j){//判断数据的大小
        while(a[j]>=temp&&j>i)
            j--;
        while(a[i]<=temp&&i<j)
            i++;
        if(a[i]>a[j]){
            n=a[i];
            a[i]=a[j];
            a[j]=n;
            flag=1;
        }
    }
    if(a[left]>a[i]){//将标志数与最后剩下的数进行交换
        a[left]=a[i];
        a[i]=temp;
        if(a[i]==temp)
            flag=1;
    }
    if(flag==1){//输出每一步的不重复过程
        b++;
        if (kbhit()) system("pause");//检测是否按键来暂停/继续
        printf("第%d步:\n",b);
        for(c=0;c<N;c++)
        printf("%d  ",a[c]);
        printf("\n\n");
        Sleep(speed);
        printf("\n");
    }
    if(left<i-1)//递归，重复上述步骤
        fastSort1(left,i-1,a);
    if(right>i+1)
        fastSort1(i+1,right,a);
}
			
/******************************** 
函数名：fastSort2
函数功能：降序的快速排序 
函数输入参数：数组 数据个数
函数返回值：无
作者：秦浩辰 
**********************************/	
void fastSort2(int left,int right,int *a){	
    int flag=0;
    i=left;//从数组的最左边和最右边分别开始寻找比最左小的数，并分别放到左边和右边
    j=right;
    temp=a[left];
    while(i<j){//判断数据的大小
        while(a[j]<=temp&&j>i)
            j--;
        while(a[i]>=temp&&i<j)
            i++;
        if(a[i]<a[j]){
            n=a[i];
            a[i]=a[j];
            a[j]=n;
            flag=1;
        }
    }
    if(a[left]<a[i]){//将标志数与最后剩下的数进行交换
        a[left]=a[i];
        a[i]=temp;
        if(a[i]==temp)
            flag=1;
    }
    if(flag==1){//输出每一步的不重复过程
        b++;
        if (kbhit()) system("pause");//检测是否按键来暂停/继续
        printf("第%d步:\n",b);
        for(c=0;c<N;c++)
        printf("%d  ",a[c]);
        printf("\n\n");
        Sleep(speed);
        printf("\n");
    }
    if(left<i-1)//递归，重复上述步骤
        fastSort2(left,i-1,a);
    if(right>i+1)
        fastSort2(i+1,right,a);
}

/******************************** 
函数名：clockFastsort1
函数功能：升序的快速排序及计时
函数输入参数：数组 数据个数
函数返回值：无
作者：秦浩辰 
备注：此函数的建立是由于递归的特性 
**********************************/
void clockFastsort1(int left,int right,int *a){
	system("cls");//清除屏幕上显示的信息
	printf("原始数据:\n");//输出原始数据
	for(i=0;i<N;i++) printf("%d  ",a[i]);
	printf("\n\n");
	Sleep(speed);
	start=clock();//开始计时
	b=0;//避免因重复调用b而导致后续输出错误 
	fastSort1(0,N-1,a);//引用升序快速排序函数 
	stop=clock();//结束计时 
	duration=(double)(stop-start)/CLK_TCK;
	printf("本次排序共耗时: %.0f(秒)\n\n",duration);
 	system("pause");
 	selectExit();//引用选择退出菜单函数  
}

/******************************** 
函数名：clockFastsort2
函数功能：降序的快速排序及计时
函数输入参数：数组 数据个数
函数返回值：无
作者：秦浩辰 
备注：此函数的建立是由于递归的特性 
**********************************/
void clockFastsort2(int left,int right,int *a){
	system("cls");//清除屏幕上显示的信息
	printf("原始数据:\n");//输出原始数据
	for(i=0;i<N;i++) printf("%d  ",a[i]);
	printf("\n\n");
	Sleep(speed);
	start=clock();//开始计时
	b=0;//避免因重复调用b而导致后续输出错误 
	fastSort2(0,N-1,a);//引用降序快速排序函数 
	stop=clock();//结束计时  
	duration=(double)(stop-start)/CLK_TCK;
	printf("本次排序共耗时: %.0f(秒)\n\n",duration);
 	system("pause");
 	selectExit();//引用选择退出菜单函数  
}

/******************************** 
函数名：blnsertsort1 
函数功能：进行升序的插入排序 
函数输入参数：数组 数据个数  
函数返回值： 无 
作者：魏濠 
**********************************/
void blnsertsort1(int *a,int N){
	system("cls");//清除屏幕上显示的信息
	printf("原始数据:\n");//输出原始数据
	for(b=0;b<N;b++) printf("%d  ",a[b]);
	printf("\n\n");
	Sleep(speed);
	start=clock();//开始计时 
    for(i=1;i<N;i++)//循环遍历 
    {
        temp=a[i];//将temp每一次赋值为a[i]  
        j=i-1;  
        while(j>=0&&temp<a[j])
        {
            a[j+1]=a[j];//将大的元素往后放 
            j--;
        }
       a[j+1]=temp;//如果插入的数比之前的大,将a[i]与a[j+1]互换
       if(a[i]!=temp){	
	   cnn=cnn+1; 
	   if (kbhit()) system("pause");//检测是否按键来暂停/继续
	   printf("第%d步:\n",cnn);//输出每一步的不重复过程
			for(k=0;k<N;k++){printf("%d  ",a[k]);}
			printf("\n\n");
			Sleep(speed);
       }
	}            
		stop=clock();//结束计时 
		duration=(double)(stop-start)/CLK_TCK;
		printf("本次排序共耗时: %.0f(秒)\n\n",duration);
 		system("pause");
		selectExit();//引用选择退出菜单函数  	
}

/******************************** 
函数名：blnsertsort2 
函数功能：进行降序的插入排序 
函数输入参数：数组 数据个数  
函数返回值： 无 
作者：魏濠 
**********************************/
void blnsertsort2(int *a,int N){
	system("cls");//清除屏幕上显示的信息	
	printf("原始数据:\n");//输出原始数据
	for(b=0;b<N;b++) printf("%d  ",a[b]);
	printf("\n\n");
	Sleep(speed);
	start=clock();//开始计时 
    for(i=1;i<N;i++) //循环遍历 
    {
        temp=a[i];//每一次将temp赋值为a[i]   
        j=i-1;  
        while(j>=0&&temp>a[j]) 
        {
            a[j+1]=a[j];//将大的元素往后放 
            j--;
        }
       a[j+1]=temp;//如果插入的数比之前的大,将a[i]与a[j+1]互换
       if(a[i]!=temp){	
	   cnn=cnn+1; 
	   if (kbhit()) system("pause");//检测是否按键来暂停/继续 
	   printf("第%d步:\n",cnn);//输出每一步的不重复过程
			for(k=0;k<N;k++){printf("%d  ",a[k]);}
			printf("\n\n");
			Sleep(speed);
       }
	}            
		stop=clock();//结束计时 
		duration=(double)(stop-start)/CLK_TCK;
		printf("本次排序共耗时: %.0f(秒)\n\n",duration);
 		system("pause");
 		selectExit();//引用选择退出菜单函数  
}
		
/******************************** 
函数名：merge1
函数功能：对数据进行升序归并处理 
函数输入参数：数组 特定相关参数 
函数返回值：无
作者：秦浩辰 
**********************************/
void merge1(int *a, int L, int M, int R){
    int i,k;
    int left[M],right[M];//设一个中间数组
    int *temp=(int *)malloc((R-L+1)*sizeof(int));
    int ll=L;
    int lh=M;
    int rl=M+1;
    int rh=R;
    for(k=0;ll<=lh&&rl<=rh;k++){//将左右两个数组进行比较，将小的交换到左边
        if(a[ll]<=a[rl]){ 
            temp[k]=a[ll++];
        }else{
            temp[k]=a[rl++];
        }
    }//将左边未分完的元素加到中间数组末尾
    if(ll<=lh){
    for(i=ll;i<=lh;i++)
        temp[k++]=a[i];
    } //将右边未分完的元素加到中间数组末尾
    if(rl<=rh){
        for(i=rl;i<=rh;i++)
            temp[k++] = a[i];
    }//将中间数组的值代入原数组
    for(i=0;i<R-L+1;i++)
        a[L+i] = temp[i];
    free(temp);
    p++;
    Sleep(speed);
	if (kbhit()) system("pause");//检测是否按键来暂停/继续 
	printf("第%d步:\n",p); 
    for(i=0;i<=R;i++){
        printf("%d  ",a[i]);
    }
    printf("\n\n");
    return;
}

/******************************** 
函数名：merge2
函数功能：对数据进行降序归并处理 
函数输入参数：数组 特定相关参数 
函数返回值：无
作者：秦浩辰 
**********************************/
void merge2(int *a, int L, int M, int R){
    int i,k;
    int left[M],right[M];//设一个中间数组
    int *temp=(int *)malloc((R-L+1)*sizeof(int));
    int ll=L;
    int lh=M;
    int rl=M+1;
    int rh=R;
    for(k=0;ll<=lh&&rl<=rh;k++){//将左右两个数组进行比较，将大的交换到左边
        if(a[ll]>=a[rl]){ 
            temp[k]=a[ll++];
        }else{
            temp[k]=a[rl++];
        }
    }//将左边未分完的元素加到中间数组末尾
    if(ll<=lh){
    for(i=ll;i<=lh;i++)
        temp[k++]=a[i];
    }//将右边未分完的元素加到中间数组末尾
    if(rl<=rh){
        for(i=rl;i<=rh;i++)
            temp[k++] = a[i];
    }//将中间数组的值代入原数组
    for(i=0;i<R-L+1;i++)
        a[L+i] = temp[i];
    free(temp);
    p++;
    Sleep(speed);
	if (kbhit()) system("pause");//检测是否按键来暂停/继续 
	printf("第%d步:\n",p); 
    for(i=0;i<=R;i++){
        printf("%d  ",a[i]);
    }
    printf("\n\n");
    return;
}

/******************************** 
函数名：mergeSort1
函数功能：升序的归并排序
函数输入参数：数组 特定相关参数 
函数返回值：无
作者：秦浩辰 
**********************************/
void mergeSort1(int *a, int L, int R){
    int M=0;
    if(L<R){
        M=(L+R)/2;//取中间值M，将数组划分为两半
        mergeSort1(a,L,M);//左右分别重复上述步骤
        mergeSort1(a,M+1,R);
        merge1(a,L,M,R);
    }
    return ;
}

/******************************** 
函数名：mergeSort2
函数功能：降序的归并排序
函数输入参数：数组 特定相关参数 
函数返回值：无
作者：秦浩辰 
**********************************/
void mergeSort2(int *a, int L, int R){
    int M=0;
    if(L<R){
        M=(L+R)/2;//取中间值M，将数组划分为两半
        mergeSort2(a,L,M);//左右分别重复上述步骤
        mergeSort2(a,M+1,R);
        merge2(a,L,M,R);
    }
    return ;
}

/******************************** 
函数名：clockMergesort1
函数功能：升序的归并排序及计时
函数输入参数：数组 特定相关参数
函数返回值：无
作者：秦浩辰  
备注：此函数的建立是由于递归的特性 
**********************************/
void clockMergesort1(int *a, int L, int R){
	system("cls");//清除屏幕上显示的信息
	printf("原始数据:\n");//输出原始数据
	for(i=0;i<N;i++) printf("%d  ",a[i]);
	printf("\n\n");
	Sleep(speed);
	start=clock();//开始计时
	p=0;//避免因重复调用p而导致后续输出错误
	R=N-1; 
	mergeSort1(a,L,R);//引用升序归并排序函数 
	stop=clock();//结束计时 
	duration=(double)(stop-start)/CLK_TCK;
	printf("本次排序共耗时: %.3f(秒)\n\n",duration);
 	system("pause");
	selectExit();//引用选择退出菜单函数 
}

/******************************** 
函数名：clockMergesort2
函数功能：降序的归并排序及计时
函数输入参数：数组 特定相关参数
函数返回值：无
作者：秦浩辰  
备注：此函数的建立是由于递归的特性 
**********************************/
void clockMergesort2(int *a, int L, int R){
	system("cls");//清除屏幕上显示的信息
	printf("原始数据:\n");//输出原始数据
	for(i=0;i<N;i++) printf("%d  ",a[i]);
	printf("\n\n");
	Sleep(speed);
	start=clock();//开始计时
	p=0;//避免因重复调用p而导致后续输出错误 
	R=N-1; 
	mergeSort2(a,L,R);//引用降序归并排序函数 
	stop=clock();//结束计时 
	duration=(double)(stop-start)/CLK_TCK;
	printf("本次排序共耗时: %.3f(秒)\n\n",duration);
 	system("pause");
	selectExit();//引用选择退出菜单函数 
}

/******************************** 
函数名：selectExit
函数功能：显示选择退出菜单 
函数输入参数：无  
函数返回值：无 
作者：胡锐 
**********************************/
void selectExit(){
	system("cls");//清除屏幕上显示的信息 
	printf("\n");
	printf("        ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
 	printf("        ┃         返回方式选择菜单        ┃\n"); 
 	printf("        ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
 	printf("        ┃            1.退出程序           ┃\n");
	printf("        ┃            2.回主菜单           ┃\n");	
	printf("        ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
	printf("\n          请按下相应数字键并回车完成操作\n");
	c=getchar( ); 	
	fflush(stdin);//清空输入缓冲区
	handleSelectExit(c);//引用处理选择退出菜单的函数 
}	
	
/******************************** 
函数名：handleSelectExit
函数功能：处理选择退出菜单 
函数输入参数：字符
函数返回值：无
作者：胡锐  
**********************************/	
void handleSelectExit(char c){
	switch(c)
{
			case '1':toExit();break;//退出程序 
			case '2':main();break;//回到主菜单 
			default:printf("您的输入有误！请重试:\n");c=getchar( );fflush(stdin);handleSelectAlg1(c);//递归式容错性处理 
		}
}

/******************************** 
函数名：toExit
函数功能：退出程序 
函数输入参数：无  
函数返回值：无 
作者：胡锐 
**********************************/
void toExit(){
	exit(0); //退出程序	
}
