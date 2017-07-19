int GetEndianness()
{
   short s = 0x0110;
   char *p = (char *) &s;
   if (p[0] == 0x10)
      return 0;// 小端格式
   else
      return 1;// 大端格式
}