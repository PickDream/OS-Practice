//彭东 @ 2021.01.09
//注释添加 mason

void _strwrite(char* string)
{   
    //显存开始地址
    char* p_strdst = (char*)(0xb8000);
    //判断NotEmpty
    while (*string)
    {
        //内存赋值
        *p_strdst = *string++;
        //指针偏移
        p_strdst += 2;
    }
    return;
}

//
void printf(char* fmt, ...)
{
    _strwrite(fmt);
    return;
}