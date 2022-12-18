#include <stdio.h>
#include <stdlib.h>

// 定义哈希表
#define MAX_SIZE 100000000

typedef struct Node
{
    long int number; // 号码
} Node;

struct Node numberList[MAX_SIZE];

long int hash(char num[])
{
    long int number=0;
    for(int i=0;num[i]!='\0';i++)
    {
        number=10*number+num[i]-48; // 字符转换成数字
    }
    return number;
}

// 插入手机号码
void insertPhoneNumber(long int phoneNumber)
{
    int index = phoneNumber % MAX_SIZE;
    Node node;
    node.number = phoneNumber;
    numberList[index] = node;
}

// 查找手机号码
int searchPhoneNumber(long int phoneNumber)
{
    int index = phoneNumber % MAX_SIZE;
    printf("ld",numberList[index].number );
    if (numberList[index].number == phoneNumber)
    {
        printf("查找成功\n");
        return 1;
    }
    printf("查找失败\n");
    return 0;
}

// 初始化哈希表
void init()
{
    char line[12];
    long int k;
    FILE *file = fopen("test.txt","r");
	if(!file)
    {
        printf("文件打开失败！");
		exit(0);
    }
	while(1)
	{
		//文件读取结束
		if(EOF == fscanf(file,"%s",line))
			break;
		// printf("%s\n",line);
        k = hash(line); // 将字符转换为数字
        insertPhoneNumber(k); // 插入号码
	}
	fclose(file);
    printf("建立成功");
}

int main(int argc, char *argv[])
{
    char ch;
    char number[12];
    while(1)
    {
        printf("1.建立\n");
        printf("2.查找\n");
        scanf("%s",&ch);
        switch (ch)
        {
        case '1': 
            init();
            break;
        case '2': 
            scanf("%s", number);
            searchPhoneNumber(hash(number));
            break;        
        default:
            printf("请重新输入");
        }        
    }

    return 0;
}
