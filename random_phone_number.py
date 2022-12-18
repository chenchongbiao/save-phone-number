import random,string

def create_phone_num(num):
    file = open('number.txt',"w")
    all_phone_nums = set()  # 存放生成的电话号码
    while True:  # 因为set会自动去重，因此死循环生成电话号码，直到等于num个号码停止
        start = random.choice(['135', '136', '137'])  # 存放前3位的号段，从中随机取一个
        end = ''.join(random.sample(string.digits, 8))  # 随机生成后面8位数字
        number = f'{start}{end}' # 拼接前3位和后8位
        all_phone_nums.add(number) # 数字加入到集合中
        file.write(f"{number}\n") # 讲电话写入文件中
        if len(all_phone_nums) >= num:  # 如果号码个数等于num，则停止
            break
        print(f'{start}{end}')
    file.close()

create_phone_num(10000 * 10000)