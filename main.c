// 定义哈希表
#define MAX_SIZE 100000000
int hashTable[MAX_SIZE];

// 初始化哈希表
void initHashTable()
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        hashTable[i] = 0;
    }
}

// 插入手机号码
void insertPhoneNumber(int phoneNumber)
{
    int index = phoneNumber % MAX_SIZE;
    hashTable[index] = phoneNumber;
}

// 查找手机号码
int searchPhoneNumber(int phoneNumber)
{
    int index = phoneNumber % MAX_SIZE;
    if (hashTable[index] == phoneNumber)
    {
        return 1;
    }
    return 0;
}